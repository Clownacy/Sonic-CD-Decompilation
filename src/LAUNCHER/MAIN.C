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

static SDL_Window *window;
static SDL_Renderer *renderer;

static SDL_Texture *sprites[800];
static SDL_Surface *sprite_surfaces[800];

static game_info state;

static int SetGrid(int, int, int, int)
{
	return 0;
}

static void EAsprset(const short x, const short y, const unsigned short index, const unsigned short link_data, const unsigned short flip)
{
	int width, height;
	SDL_QueryTexture(sprites[index], NULL, NULL, &width, &height);
	SDL_Rect rect;
	rect.x = x - 0x80;
	rect.y = y - 0x80;
	rect.w = width;
	rect.h = height;
	SDL_RenderCopy(renderer, sprites[index], NULL, &rect);
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

	SDL_Palette* const palette = SDL_AllocPalette(16);

	if (palette == NULL)
		fputs("Failed to allocate palette.\n", stderr);

	for (unsigned int i = 0; i < 16; ++i)
	{
		SDL_Color colour;
		colour.r = i * 0xFF / 15;
		colour.g = 0;
		colour.b = 0;
		colour.a = 0xFF;

		SDL_SetPaletteColors(palette, &colour, i, 1);
	}

	for (unsigned long i = 0; i < total_sprites; ++i)
	{
		ReadU16LE(file);
		ReadU16LE(file);
		const unsigned int width = ReadU16LE(file);
		const unsigned int padded_width = (width + 7) & ~7U;
		const unsigned int height = ReadU16LE(file);
		ReadU16LE(file);
		ReadU16LE(file);

		sprite_surfaces[i] = SDL_CreateRGBSurfaceWithFormat(0, padded_width, height, 0, SDL_PIXELFORMAT_INDEX4MSB);

		if (sprite_surfaces[i] == NULL)
			fputs("Failed to create surface.\n", stderr);

		if (SDL_SetSurfacePalette(sprite_surfaces[i], palette) < 0)
			fputs("Failed to set surface palette.\n", stderr);
	}

	fseek(file, sprite_offset, SEEK_SET);

	for (unsigned long i = 0; i < total_sprites; ++i)
	{
		if (fread(sprite_surfaces[i]->pixels, sprite_surfaces[i]->w * sprite_surfaces[i]->h / 2, 1, file) != 1)
			fputs("Failed to read sprite bytes.\n", stderr);

		sprites[i] = SDL_CreateTextureFromSurface(renderer, sprite_surfaces[i]);
		SDL_FreeSurface(sprite_surfaces[i]);

		if (sprites[i] == NULL)
			fputs("Failed to create texture.\n", stderr);
	}

	fclose(file);

	return true;
}

int SDL_main(const int argc, char** const argv)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

	SDL_CreateWindowAndRenderer(320, 240, 0, &window, &renderer);
	SDL_RenderSetVSync(renderer, 1);

	if (!LoadSprites("R1/11A/SCMP11A.CMP"))
		fputs("Failed to load sprites.\n", stderr);

	static void *buffer_pointers2[COUNT_OF(buffers)];
	for (unsigned int i = 0; i < COUNT_OF(buffers); ++i)
		buffer_pointers2[i] = &buffers[i];

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

		ExportedFunctions.game();

		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
	}

	ExportedFunctions.dll_memfree();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
