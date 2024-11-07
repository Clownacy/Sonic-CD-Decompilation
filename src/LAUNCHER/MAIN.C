#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SDL.h"

#include "../TYPES.H"

#define COUNT_OF(x) (sizeof(x) / sizeof(x[0]))

extern dlink_export ExportedFunctions;

static unsigned char buffers[10][1024*1024*10];

static PALETTEENTRY raw_palettes[4][64];

static SDL_Window *window;
static SDL_Palette *palette;
static SDL_Surface *framebuffer;

static SDL_Surface *sprites[800];

static game_info state;

static int SetGrid(int, int, int, int)
{
	return 0;
}

static void EAsprset(const short x, const short y, const unsigned short index, const unsigned short link_data, const unsigned short flip)
{
	SDL_Rect destination_rectangle;
	destination_rectangle.x = x - 0x80;
	destination_rectangle.y = y - 0x80;
	destination_rectangle.w = 0;
	destination_rectangle.h = 0;
	if (SDL_BlitSurface(sprites[index], NULL, framebuffer, &destination_rectangle) == -1)
		fputs("Failed to bit to framebuffer surface.\n", stderr);
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

static void sMemSet(void* const buffer, const unsigned char value, const int size)
{
	memset(buffer, value, size);
}

static void sMemCpy(void* const destination, void* const source, const int size)
{
	memcpy(destination, source, size);
}

static int sRandom()
{
	return rand();
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

static unsigned long ReadUnsignedLE(FILE* const file, const unsigned int total_bytes)
{
	unsigned char bytes[4];
	fread(bytes, 1, total_bytes, file);

	unsigned long result = 0;
	for (unsigned int i = 0; i < total_bytes; ++i)
		result |= bytes[i] << i * 8;
	return result;
}

static unsigned long ReadU32LE(FILE* const file)
{
	return ReadUnsignedLE(file, 4);
}

static unsigned long ReadU16LE(FILE* const file)
{
	return ReadUnsignedLE(file, 2);
}

static bool LoadSprites(const char* const path)
{
	FILE *file = fopen(path, "rb");

	if (file == NULL)
		return false;

	fseek(file, 8, SEEK_SET);

	const unsigned long total_sprites = ReadU32LE(file);
	const unsigned long sprite_offset = ReadU32LE(file);

	fseek(file, sprite_offset, SEEK_SET);

	for (unsigned long i = 0; i < total_sprites; ++i)
	{
		fpos_t previous_position;
		fgetpos(file, &previous_position);

		fseek(file, 0x10 + i * 0xC, SEEK_SET);

		ReadU16LE(file);
		ReadU16LE(file);
		const unsigned int width = ReadU16LE(file);
		const unsigned int padded_width = (width + 7) & ~7U;
		const unsigned int height = ReadU16LE(file);
		const unsigned int palette_offset = ReadU16LE(file) - 16;
		ReadU16LE(file);

		fseek(file, previous_position, SEEK_SET);

		const int total_pixel_bytes = padded_width * height / 2;

		sprites[i] = SDL_CreateRGBSurfaceWithFormat(0, padded_width, height, 0, SDL_PIXELFORMAT_INDEX8);

		if (sprites[i] == NULL)
		{
			fputs("Failed to create surface.\n", stderr);
		}
		else
		{
			unsigned char *pixels = sprites[i]->pixels;

			for (int j = 0; j < total_pixel_bytes; ++j)
			{
				const unsigned char packed_pixels = fgetc(file);

				// Redirect all transparent pixels to colour 0.
				*pixels = palette_offset + (packed_pixels >> 4);
				*pixels = *pixels % 0x10 == 0 ? 0 : *pixels;
				++pixels;

				*pixels = palette_offset + (packed_pixels & 0xF);
				*pixels = *pixels % 0x10 == 0 ? 0 : *pixels;
				++pixels;
			}

			// Also make them share the same palette.
			if (SDL_SetSurfacePalette(sprites[i], palette) < 0)
				fputs("Failed to set surface palette.\n", stderr);

			// Make colour 0 transparent.
			if (SDL_SetColorKey(sprites[i], SDL_TRUE, 0) < 0)
				fputs("Failed to set surface colour key.\n", stderr);
		}

		fsetpos(file, &previous_position);
		fseek(file, total_pixel_bytes, SEEK_CUR);
	}

	fclose(file);

	return true;
}

int SDL_main(const int argc, char** const argv)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

	window = SDL_CreateWindow("Sonic CD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 320, 224, 0);

	if (window == NULL)
	{
		fputs("Failed to create window.\n", stderr);
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
			framebuffer = SDL_CreateRGBSurfaceWithFormat(0, 320, 224, 0, SDL_PIXELFORMAT_INDEX8);

			if (framebuffer == NULL)
			{
				fputs("Failed to create framebuffer surface.\n", stderr);
			}
			else
			{
				if (SDL_SetSurfacePalette(framebuffer, palette) < 0)
					fputs("Failed to set framebuffer palette.\n", stderr);

				if (!LoadSprites("R1/11A/SCMP11A.CMP"))
				{
					fputs("Failed to load sprites.\n", stderr);
				}
				else
				{
					static void *buffer_pointers2[COUNT_OF(buffers)];
					for (unsigned int i = 0; i < COUNT_OF(buffers); ++i)
						buffer_pointers2[i] = &buffers[i];

					buffer_pointers2[1] = &raw_palettes[0];
					buffer_pointers2[2] = &raw_palettes[1];
					buffer_pointers2[3] = &raw_palettes[2];
					buffer_pointers2[4] = &raw_palettes[3];

					static void *buffer_pointers[COUNT_OF(buffers)];
					for (unsigned int i = 0; i < COUNT_OF(buffers); ++i)
						buffer_pointers[i] = &buffer_pointers2[i];

					for (unsigned int i = 6; i < COUNT_OF(buffers); ++i)
						buffer_pointers[i] = &buffers[i];

					buffer_pointers[7] = &state;

					state.time_flag = 1; // Past?

					static void* const function_pointers[] = {
						SetGrid,
						EAsprset,
						ClrSpriteDebug,
						WaveRequest,
						CDPlay,
						CDPause,
						ChangeTileBmp,
						NULL,
						NULL,
						NULL,
						WaveAllStop,
						NULL,
						NULL,
						sMemSet,
						sMemCpy,
						NULL,
						sRandom,
						NULL,
						NULL,
						NULL,
						sPrintf,
						sOutputDebugString,
						sOpenFile,
						sReadFile,
						sCloseFile,
						NULL,
					};

					ExportedFunctions.dll_meminit((char***)buffer_pointers, (void**)function_pointers);
					ExportedFunctions.game_init();

					bool alive = true;
					while (alive)
					{
						SDL_Event event;
						while (SDL_PollEvent(&event))
						{
							switch (event.type)
							{
								case SDL_QUIT:
									alive = false;
									break;
							}
						}

						const Uint8* const keyboard_state = SDL_GetKeyboardState(NULL);
						unsigned short swdata = 0;
						if (keyboard_state[SDL_SCANCODE_SPACE])
							swdata |= 0x10;
						if (keyboard_state[SDL_SCANCODE_UP])
							swdata |= 0x100;
						if (keyboard_state[SDL_SCANCODE_DOWN])
							swdata |= 0x200;
						if (keyboard_state[SDL_SCANCODE_LEFT])
							swdata |= 0x400;
						if (keyboard_state[SDL_SCANCODE_RIGHT])
							swdata |= 0x800;
						ExportedFunctions.SWdataSet(swdata, 0);

						// Clear framebuffer.
						SDL_FillRect(framebuffer, NULL, 0);

						ExportedFunctions.game();

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

						if (SDL_BlitSurface(framebuffer, NULL, SDL_GetWindowSurface(window), NULL) == -1)
							fputs("Failed to blit to window surface.\n", stderr);

						SDL_UpdateWindowSurface(window);
						const int frames_per_second = 60;
						SDL_Delay((1000 + (frames_per_second / 2)) / frames_per_second);
					}

					ExportedFunctions.dll_memfree();
				}

				SDL_FreeSurface(framebuffer);
			}

			SDL_FreePalette(palette);
		}

		SDL_DestroyWindow(window);
	}

	SDL_Quit();

	return EXIT_SUCCESS;
}
