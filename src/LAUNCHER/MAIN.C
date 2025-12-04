#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SDL.h"

#include "../TYPES.H"

#include "COMMON.H"
#include "IO.H"
#include "SZDD.H"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 224

#define TILE_WIDTH_SHIFT 3
#define TILE_WIDTH (1 << TILE_WIDTH_SHIFT)
#define TILE_HEIGHT 8

#define STRINGIFY2(X) #X
#define STRINGIFY(X) STRINGIFY2(X)

#define ROUND_IDENTIFIER "R"STRINGIFY(LEVEL_ROUND)
#define LEVEL_IDENTIFIER STRINGIFY(LEVEL_ROUND)STRINGIFY(LEVEL_ZONE)STRINGIFY(LEVEL_TIME)

#define TEXTURE_FORMAT SDL_PIXELFORMAT_BGRX8888

#define WINDOW_SCALE 2

typedef struct SpriteQueueSlot
{
	short x, y;
	unsigned short index, link_data, flip;
} SpriteQueueSlot;

extern dlink_export ExportedFunctions;

static unsigned char buffers[10][1024*1024*10];

static PALETTEENTRY raw_palettes[4][64];
static short hscroll_buffer[SCREEN_HEIGHT + 0x10][2];

static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Texture *texture;
static SDL_Surface *surface;
static SDL_Palette *palette;
static SDL_Surface *framebuffer;

// TODO: Dynamically allocate based on what the file says the number of sprites are?
static SDL_Surface *sprites[700][2][2];

// TODO: Dynamically allocate based on what the file says the number of tiles are?
static unsigned long tile_lines[0x800][TILE_HEIGHT];

static game_info state;

typedef unsigned short Block;

static Block planes[2][32][64];

static SpriteQueueSlot sprite_queue[80];
static unsigned int sprite_queue_index;

static unsigned char buttons_held, buttons_pressed;

static int SetGrid(const int plane, const int x, const int y, const int block, const int flip)
{
	// TODO: Flip.
	planes[plane][y][x] = block ^ flip;
	return 0;
}

static void EAsprset(const short x, const short y, const unsigned short index, const unsigned short link_data, const unsigned short flip)
{
	if (sprite_queue_index == COUNT_OF(sprite_queue))
		return;

	sprite_queue[sprite_queue_index].x = x;
	sprite_queue[sprite_queue_index].y = y;
	sprite_queue[sprite_queue_index].index = index;
	sprite_queue[sprite_queue_index].link_data = link_data;
	sprite_queue[sprite_queue_index].flip = flip;
	++sprite_queue_index;
}

static void ClrSpriteDebug()
{
	
}

static void WaveRequest(short)
{
	
}

static void CDPlay(short)
{
	
}

static void CDPause(short)
{
	
}

static void ChangeTileBmp(int, int)
{
	
}

static void WaveAllStop()
{
	
}

static void* sMemAlloc(const int size)
{
	return malloc(size);
}

static void sMemFree(void* const buffer)
{
	free(buffer);
}

static void sMemSet(void* const buffer, const unsigned char value, const int size)
{
	memset(buffer, value, size);
}

static void sMemCpy(void* const destination, const void* const source, const int size)
{
	memcpy(destination, source, size);
}

static int sMemCmp(const void* const lhs, const void* const rhs, const int size)
{
	return memcmp(lhs, rhs, size);
}

static int sRandom()
{
	return rand();
}

static char* sStrcpy(char* const destination, const char* const source)
{
	return strcpy(destination, source);
}

static char* sStrncpy(char* const destination, const char* const source, const int size)
{
	return strncpy(destination, source, size);
}

static int sStrncmp(const char* const lhs, const char* const rhs, const int size)
{
	return strncmp(lhs, rhs, size);
}

static void sPrintf(char* const buffer, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vsprintf(buffer, fmt, args);
	va_end(args);
}

static void sOutputDebugString(char* const string)
{
	fputs(string, stderr);
}

static FILE *files[0x10];
static unsigned int files_index;

static int sOpenFile(char* const filename)
{
	files_index = (files_index + 1) % COUNT_OF(files);
	files[files_index] = fopen(filename, "rb");
	return files[files_index] == NULL ? -1 : files_index;
}

static int sReadFile(const int file_handle, void* const buffer, const int size)
{
	return fread(buffer, 1, size, files[file_handle]);
}

static void sCloseFile(const int file_handle)
{
	fclose(files[file_handle]);
}

static SDL_Surface* CreateSpriteSurface(const int width, const int height)
{
	SDL_Surface* const surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 0, SDL_PIXELFORMAT_INDEX8);

	if (surface == NULL)
	{
		fputs("Failed to create surface.\n", stderr);
	}
	else
	{
		// Also make them share the same palette.
		if (SDL_SetSurfacePalette(surface, palette) < 0)
			fputs("Failed to set surface palette.\n", stderr);

		// Make colour 0 transparent.
		if (SDL_SetColorKey(surface, SDL_TRUE, 0) < 0)
			fputs("Failed to set surface colour key.\n", stderr);
	}

	return surface;
}

static unsigned long ReadUnsignedLEP(const unsigned char** const pointer, const unsigned int total_bytes)
{
	unsigned int i;
	unsigned long value = 0;

	for (i = 0; i < total_bytes; ++i)
		value |= (unsigned long)(*pointer)[i] << (i * 8);

	*pointer += total_bytes;

	return value;
}

static unsigned long ReadUnsignedBEP(const unsigned char** const pointer, const unsigned int total_bytes)
{
	unsigned int i;
	unsigned long value = 0;

	for (i = 0; i < total_bytes; ++i)
	{
		value <<= 8;
		value |= (*pointer)[i];
	}

	*pointer += total_bytes;

	return value;
}

static unsigned long ReadU16LEP(const unsigned char** const pointer)
{
	return ReadUnsignedLEP(pointer, 2);
}

static unsigned long ReadU32LEP(const unsigned char** const pointer)
{
	return ReadUnsignedLEP(pointer, 4);
}

static unsigned long ReadU32BEP(const unsigned char** const pointer)
{
	return ReadUnsignedBEP(pointer, 4);
}

static signed long ReadSignedLEP(const unsigned char** const pointer, const unsigned int total_bytes)
{
	return ReadSigned(ReadUnsignedLEP(pointer, total_bytes), total_bytes);
}

static signed long ReadS16LEP(const unsigned char** const pointer)
{
	return ReadSignedLEP(pointer, 2);
}

static signed long ReadS32LEP(const unsigned char** const pointer)
{
	return ReadSignedLEP(pointer, 4);
}

static bool LoadSprites(const char* const path)
{
	bool success = false;

	unsigned char* const buffer;
	size_t buffer_size;
	if (!SZDD_Expand(path, (void**)&buffer, &buffer_size))
		return false;

	const unsigned char *pointer;

	pointer = buffer + 8;

	const unsigned long total_sprites = ReadU32LEP(&pointer);

	if (total_sprites > COUNT_OF(sprites))
	{
		fputs("Too many sprites.\n", stderr);
	}
	else
	{
		const unsigned long sprite_offset = ReadU32LEP(&pointer);

		pointer = buffer + sprite_offset;

		for (unsigned long i = 0; i < total_sprites; ++i)
		{
			const unsigned char* const previous_pointer = pointer;

			pointer = buffer + 0x10 + i * 0xC;

			ReadS16LEP(&pointer);
			ReadS16LEP(&pointer);
			const unsigned int width = ReadU16LEP(&pointer);
			const unsigned int padded_width = (width + 7) & ~7U;
			const unsigned int height = ReadU16LEP(&pointer);
			const unsigned int palette_offset = ReadU16LEP(&pointer) - 16;
			ReadU16LEP(&pointer);

			state.pSprBmp[i].xs = padded_width;
			state.pSprBmp[i].ys = height;

			pointer = previous_pointer;

			const int total_pixel_bytes = padded_width * height / 2;

			for (unsigned int y_flip = 0; y_flip < 2; ++y_flip)
			{
				for (unsigned int x_flip = 0; x_flip < 2; ++x_flip)
				{
					SDL_Surface* const sprite = CreateSpriteSurface(padded_width, height);

					if (sprite != NULL)
					{
						unsigned char *pixels = sprite->pixels;

						if (x_flip == 0 && y_flip == 0)
						{
							for (int j = 0; j < total_pixel_bytes; ++j)
							{
								const unsigned char packed_pixels = *pointer++;

								// Redirect all transparent pixels to colour 0.
								*pixels = palette_offset + (packed_pixels >> 4);
								*pixels = *pixels % 0x10 == 0 ? 0 : *pixels;
								++pixels;

								*pixels = palette_offset + (packed_pixels & 0xF);
								*pixels = *pixels % 0x10 == 0 ? 0 : *pixels;
								++pixels;
							}
						}
						else
						{
							unsigned char* const base_pixels = sprites[i][0][0]->pixels;

							for (int y = 0; y < height; ++y)
							{
								const int base_y = y_flip != 0 ? height - y - 1 : y;
								unsigned char* const line = pixels + y * padded_width;
								unsigned char* const base_line = base_pixels + base_y * padded_width;

								if (x_flip != 0)
								{
									for (int x = 0; x < padded_width; ++x)
									{
										const int base_x = padded_width - x - 1;

										line[x] = base_line[base_x];
									}
								}
								else
								{
									memcpy(line, base_line, padded_width);
								}
							}
						}
					}

					sprites[i][y_flip][x_flip] = sprite;
				}
			}

			pointer = previous_pointer + total_pixel_bytes;
		}

		success = true;
	}

	free(buffer);

	return success;
}

static bool LoadTiles(const char* const path)
{
	bool success = false;

	unsigned char* const buffer;
	size_t buffer_size;
	if (!SZDD_Expand(path, (void**)&buffer, &buffer_size))
		return false;

	const unsigned char *pointer;

	pointer = buffer + 8;

	const unsigned long total_tiles = ReadU32LEP(&pointer);

	if (total_tiles > COUNT_OF(tile_lines))
	{
		fputs("Too many tiles.\n", stderr);
	}
	else
	{
		const unsigned long tiles_offset = ReadU32LEP(&pointer);

		pointer = buffer + tiles_offset;

		for (unsigned long i = 0; i < total_tiles; ++i)
			for (int j = 0; j < TILE_HEIGHT; ++j)
				tile_lines[i][j] = ReadU32BEP(&pointer);

		success = true;
	}

	free(buffer);

	return success;
}

static void DrawTileLine(unsigned char* const output, const unsigned long input, const bool x_flip, const unsigned int palette_line, const unsigned int min, const unsigned int max)
{
	for (unsigned int i = min; i < max; ++i)
	{
		const unsigned int source_i = i ^ (x_flip ? 0 : 7);
		const unsigned int destination_i = i;

		const unsigned int value = (input >> (4 * source_i)) & 0xF;

		if (value != 0)
			output[destination_i] = palette_line * 0x10 + value;
	}
}

static void DrawTileLineWhole(unsigned char* const output, const unsigned long input, const bool x_flip, const unsigned int palette_line)
{
	DrawTileLine(output, input, x_flip, palette_line, 0, TILE_WIDTH);
}

static void DrawPlanes(const bool target_priority)
{
	const unsigned long vscroll = ExportedFunctions.Get_vscroll();
	unsigned int vscrolls[2];
	vscrolls[0] = vscroll >> 16;
	vscrolls[1] = vscroll & 0xFFFF;

	unsigned int hscrolls[2];
	hscrolls[0] = ExportedFunctions.Get_scra_h_posiw() >> 16;
	hscrolls[1] = ExportedFunctions.Get_scrb_h_posiw() >> 16;

	unsigned char* const framebuffer_pixels = framebuffer->pixels;

	for (unsigned int plane_inv = 0; plane_inv < COUNT_OF(planes); ++plane_inv)
	{
		const unsigned int plane = plane_inv ^ 1;

		for (unsigned int y = 0; y < SCREEN_HEIGHT; ++y)
		{
			unsigned char* const framebuffer_line_pixels = &framebuffer_pixels[y * framebuffer->pitch];

			const unsigned int screen_width_in_tiles = DIVIDE_CEILING(SCREEN_WIDTH + (TILE_WIDTH - 1), TILE_WIDTH);
			for (unsigned int tile_x = 0; tile_x < screen_width_in_tiles; ++tile_x)
			{
				const unsigned int hscroll = plane == 0 ? hscrolls[plane] : -hscroll_buffer[y][plane ^ 1];

				const unsigned int x_offset = hscroll % TILE_WIDTH;
				unsigned char* const framebuffer_tile_line_pixels = &framebuffer_line_pixels[tile_x * TILE_WIDTH - x_offset];

				const unsigned int src_x = (hscroll / TILE_WIDTH + tile_x) % COUNT_OF(planes[plane][y]);
				const unsigned int src_y = ((vscrolls[plane] + y) / TILE_HEIGHT) % COUNT_OF(planes[plane]);
				const unsigned int tile_metadata = planes[plane][src_y][src_x];
				const unsigned int tile_index = tile_metadata & 0x7FF;

				//if (tile_index == 0)
				//	continue;

				unsigned long* const tile = tile_lines[tile_index];
				const bool x_flip = (tile_metadata & 0x800) != 0;
				const bool y_flip = (tile_metadata & 0x1000) != 0;
				const unsigned int tile_line_y = ((vscrolls[plane] + y) % 8) ^ (y_flip ? 7 : 0);
				const unsigned int palette_line = (tile_metadata >> 13) & 3;
				const bool priority = (tile_metadata & 0x8000) != 0;

				if (priority != target_priority)
					continue;

				if (tile_x == 0)
					DrawTileLine(framebuffer_tile_line_pixels, tile[tile_line_y], x_flip, palette_line, x_offset, TILE_WIDTH);
				else if (tile_x >= screen_width_in_tiles - 1)
					DrawTileLine(framebuffer_tile_line_pixels, tile[tile_line_y], x_flip, palette_line, 0, x_offset);
				else
					DrawTileLineWhole(framebuffer_tile_line_pixels, tile[tile_line_y], x_flip, palette_line);
			}
		}
	}
}

static void DrawSprites(const bool target_priority)
{
	for (unsigned int i = sprite_queue_index; i-- != 0; )
	{
		const SpriteQueueSlot* const sprite = &sprite_queue[i];

		const bool priority = (sprite->flip & 0x8000) != 0;

		if (priority != target_priority)
			continue;

		const unsigned int x_flip = (sprite->flip >> 0) & 1;
		const unsigned int y_flip = (sprite->flip >> 1) & 1;

		SDL_Rect destination_rectangle;
		destination_rectangle.x = sprite->x - 0x80;
		destination_rectangle.y = sprite->y - 0x80;
		destination_rectangle.w = 0;
		destination_rectangle.h = 0;

		if (SDL_BlitSurface(sprites[sprite->index][y_flip][x_flip], NULL, framebuffer, &destination_rectangle) == -1)
			fputs("Failed to blit to framebuffer surface.\n", stderr);
	}
}

static void DoButton(const bool pressed, const unsigned char index)
{
	const unsigned int mask = 1 << index;

	buttons_held &= ~mask;
	if (pressed)
		buttons_held |= mask;
}

static void GameMain(void)
{
	static void *buffer_pointers2[COUNT_OF(buffers)];
	for (unsigned int i = 0; i < COUNT_OF(buffers); ++i)
		buffer_pointers2[i] = &buffers[i];

	buffer_pointers2[1] = &raw_palettes[0];
	buffer_pointers2[2] = &raw_palettes[1];
	buffer_pointers2[3] = &raw_palettes[2];
	buffer_pointers2[4] = &raw_palettes[3];
	buffer_pointers2[5] = &hscroll_buffer;

	static void *buffer_pointers[COUNT_OF(buffers)];
	for (unsigned int i = 0; i < COUNT_OF(buffers); ++i)
		buffer_pointers[i] = &buffer_pointers2[i];

	for (unsigned int i = 6; i < COUNT_OF(buffers); ++i)
		buffer_pointers[i] = &buffers[i];

	buffer_pointers[7] = &state;

	state.stageno.b.h = LEVEL_ROUND - 1;
	state.stageno.b.l = LEVEL_ZONE - 1;

	/* R2 is skipped. */
	if (state.stageno.b.h > 1)
		--state.stageno.b.h;

	switch (STRINGIFY(LEVEL_TIME)[0])
	{
		default:
			fputs("Bad level time.\n", stderr);
			/* Fallthrough */
		case 'A':
			state.time_flag = 1;
			break;
		case 'B':
			state.time_flag = 0;
			break;
		case 'C':
			state.time_flag = 2;
			state.generate_flag = 1;
			break;
		case 'D':
			state.time_flag = 2;
			break;
	}

	static void* const function_pointers[] = {
		SetGrid,
		EAsprset,
		ClrSpriteDebug,
		WaveRequest,
		CDPlay,
		CDPause,
		ChangeTileBmp,
		NULL, // ReadScoreIndx
		NULL, // WriteScoreData
		NULL, // SetScoreDate
		WaveAllStop,

		sMemAlloc,
		sMemFree,
		sMemSet,
		sMemCpy,
		sMemCmp,
		sRandom,
		sStrcpy,
		sStrncpy,
		sStrncmp,
		sPrintf,
		sOutputDebugString,
		sOpenFile,
		sReadFile,
		sCloseFile,
		NULL, // enableSubMenuItem?
		// TODO: Little Planet uses WAY more functions than just these,
		// including a mysterious 'read peripheral pad' function.
	};

	ExportedFunctions.dll_meminit((char***)buffer_pointers, (void**)function_pointers);

	if (!LoadSprites(ROUND_IDENTIFIER"/"LEVEL_IDENTIFIER"/SCMP"LEVEL_IDENTIFIER".CM_"))
	{
		fputs("Failed to load sprites.\n", stderr);
	}
	else if (!LoadTiles(ROUND_IDENTIFIER"/"LEVEL_IDENTIFIER"/TCMP"LEVEL_IDENTIFIER".CM_"))
	{
		fputs("Failed to load tiles.\n", stderr);
	}
	else
	{
		ExportedFunctions.game_init();

		bool alive = true;
		Uint32 next_ticks = SDL_GetTicks();
		while (alive)
		{
			buttons_pressed = buttons_held;

			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
					case SDL_QUIT:
						alive = false;
						break;

					case SDL_KEYDOWN:
					case SDL_KEYUP:
					{
						if (event.key.repeat)
							break;

						const bool pressed = event.key.state == SDL_PRESSED;

						switch (event.key.keysym.scancode)
						{
							case SDL_SCANCODE_UP:
								DoButton(pressed, 0);
								break;

							case SDL_SCANCODE_DOWN:
								DoButton(pressed, 1);
								break;

							case SDL_SCANCODE_LEFT:
								DoButton(pressed, 2);
								break;

							case SDL_SCANCODE_RIGHT:
								DoButton(pressed, 3);
								break;

							case SDL_SCANCODE_SPACE:
							case SDL_SCANCODE_Z:
								DoButton(pressed, 4);
								break;

							case SDL_SCANCODE_X:
								DoButton(pressed, 5);
								break;

							case SDL_SCANCODE_C:
								DoButton(pressed, 6);
								break;

							case SDL_SCANCODE_ESCAPE:
								DoButton(pressed, 7);
								break;
						}

						break;
					}
				}
			}

			buttons_pressed ^= buttons_held;
			buttons_pressed &= buttons_held;

			ExportedFunctions.SWdataSet(buttons_held << 8 | buttons_pressed << 0, 0);

			ExportedFunctions.game();

			// Clear framebuffer.
			SDL_FillRect(framebuffer, NULL, 0);

			DrawPlanes(false);
			DrawSprites(false);
			DrawPlanes(true);
			DrawSprites(true);
			sprite_queue_index = 0;

			// Update the colour palette.
			for (unsigned int i = 0; i < COUNT_OF(raw_palettes[1]); ++i)
			{
				SDL_Color colour;
				colour.r = raw_palettes[1][i].peRed;
				colour.g = raw_palettes[1][i].peGreen;
				colour.b = raw_palettes[1][i].peBlue;
				colour.a = 0xFF;

				if (SDL_SetPaletteColors(palette, &colour, i, 1) < 0)
					fputs("Failed to set framebuffer palette colour.\n", stderr);
			}

			if (SDL_LockTexture(texture, NULL, &surface->pixels, &surface->pitch) < 0)
			{
				fputs("Failed to lock texture surface.\n", stderr);
			}
			else
			{
				if (SDL_BlitScaled(framebuffer, NULL, surface, NULL) == -1)
					fputs("Failed to blit to window surface.\n", stderr);

				SDL_UnlockTexture(texture);

				SDL_RenderCopy(renderer, texture, NULL, NULL);
				SDL_RenderPresent(renderer);
			}

			const Uint32 current_ticks = SDL_GetTicks();
			if (next_ticks > current_ticks)
				SDL_Delay(next_ticks - current_ticks);
			const int frames_per_second = 60;
			next_ticks += (1000 + (frames_per_second / 2)) / frames_per_second;
		}
	}

	ExportedFunctions.dll_memfree();
}

int main(const int argc, char** const argv)
{
	SDL_SetHint(SDL_HINT_WINDOWS_DPI_SCALING, "1");

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

	window = SDL_CreateWindow("Sonic CD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH * WINDOW_SCALE, SCREEN_HEIGHT * WINDOW_SCALE, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

	if (window == NULL)
	{
		fputs("Failed to create window.\n", stderr);
	}
	else
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

		if (renderer == NULL)
		{
			fputs("Failed to create renderer.\n", stderr);
		}
		else
		{
			SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
			//SDL_RenderSetIntegerScale(renderer, SDL_TRUE);

			texture = SDL_CreateTexture(renderer, TEXTURE_FORMAT, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

			if (texture == NULL)
			{
				fputs("Failed to create texture.\n", stderr);
			}
			else
			{
				surface = SDL_CreateRGBSurfaceWithFormatFrom(NULL, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_BITSPERPIXEL(TEXTURE_FORMAT), 0, TEXTURE_FORMAT);

				if (surface == NULL)
				{
					fputs("Failed to create texture surface.\n", stderr);
				}
				else
				{
					palette = SDL_AllocPalette(0x100);

					if (palette == NULL)
					{
						fputs("Failed to allocate palette.\n", stderr);
					}
					else
					{
						framebuffer = SDL_CreateRGBSurfaceWithFormat(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_PIXELFORMAT_INDEX8);

						if (framebuffer == NULL)
						{
							fputs("Failed to create framebuffer surface.\n", stderr);
						}
						else
						{
							if (SDL_SetSurfacePalette(framebuffer, palette) < 0)
								fputs("Failed to set framebuffer palette.\n", stderr);

							GameMain();

							SDL_FreeSurface(framebuffer);
						}

						SDL_FreePalette(palette);
					}

					SDL_FreeSurface(surface);
				}

				SDL_DestroyTexture(texture);
			}

			SDL_DestroyRenderer(renderer);
		}

		SDL_DestroyWindow(window);
	}

	SDL_Quit();

	return EXIT_SUCCESS;
}
