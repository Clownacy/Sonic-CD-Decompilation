#include "SZDD.H"

#include <stdlib.h>
#include <string.h>

#include "IO.H"
#include "LZSS.H"

#define SZDD_MAGIC_SIZE 8

int SZDD_Expand(const char* const file_path, void** const buffer, size_t* const buffer_size)
{
	int exit_code = 0;
	FILE* const file = fopen(file_path, "rb");

	if (file != NULL)
	{
		static const unsigned char header_magic[SZDD_MAGIC_SIZE] = {0x53, 0x5A, 0x44, 0x44, 0x88, 0xF0, 0x27, 0x33};
		unsigned char header_buffer[SZDD_MAGIC_SIZE];

		if (fread(header_buffer, 1, SZDD_MAGIC_SIZE, file) == SZDD_MAGIC_SIZE
		 && memcmp(header_buffer, header_magic, SZDD_MAGIC_SIZE) == 0
		 && fgetc(file) == 'A')
		{
			(void)fgetc(file); /* Missing filename character; unused. */
			*buffer_size = ReadU32LE(file);

			*buffer = malloc(*buffer_size);

			if (*buffer != NULL)
			{
				LZSS_Decode(file, *buffer, *buffer_size);
				exit_code = 1;
			}
		}

		fclose(file);
	}

	return exit_code;
}
