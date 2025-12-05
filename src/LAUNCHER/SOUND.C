#include "SOUND.H"

#include <stdlib.h>
#include <string.h>

#include "vgmstream/src/libvgmstream.h"

typedef struct Sound
{
	int16_t *buffer;
	size_t length, position;
	cc_bool playing;
} Sound;

static libvgmstream_t* state;
static cc_bool music_playing;

static Sound sounds[0x80];

cc_bool Sound_Initialise(void)
{
	cc_bool success = cc_false;

	state = libvgmstream_init();

	if (state != NULL)
	{
		size_t i;

		for (i = 0; i < COUNT_OF(sounds); ++i)
		{
			libstreamfile_t* const file = libstreamfile_open_from_stdio("SE.ACX");

			if (file != NULL)
			{
				libvgmstream_close_stream(state);

				libvgmstream_config_t config = {};
				config.auto_downmix_channels = SOUND_CHANNELS;
				config.force_sfmt = LIBVGMSTREAM_SFMT_PCM16;
				libvgmstream_setup(state, &config);

				const int result = libvgmstream_open_stream(state, file, i + 1);
				libstreamfile_close(file);

				if (result >= 0)
				{
					sounds[i].buffer = (int16_t*)malloc(state->format->stream_samples * state->format->sample_size * state->format->channels);

					if (sounds[i].buffer != NULL)
					{
						sounds[i].length = state->format->stream_samples;
						sounds[i].position = 0;

						libvgmstream_fill(state, sounds[i].buffer, sounds[i].length);
					}
				}

				libvgmstream_close_stream(state);
			}
		}

		success = cc_true;
	}

	return success;
}

void Sound_Deinitialise(void)
{
	libvgmstream_free(state);
	state = NULL;
}

cc_bool Sound_PlayMusic(const char* const file_path, const unsigned int index, const cc_bool loop)
{
	libstreamfile_t* const file = libstreamfile_open_from_stdio(file_path);

	if (file != NULL)
	{
		libvgmstream_close_stream(state);

		libvgmstream_config_t config = {};
		config.allow_play_forever = true;
		config.play_forever = true;
		config.force_loop = loop;
		config.auto_downmix_channels = SOUND_CHANNELS;
		config.force_sfmt = LIBVGMSTREAM_SFMT_PCM16;
		libvgmstream_setup(state, &config);

		const int result = libvgmstream_open_stream(state, file, index - 1);
		libstreamfile_close(file);

		if (result >= 0)
		{
			music_playing = cc_true;
			return cc_true;
		}
	}

	return cc_false;
}

void Sound_PlaySound(const unsigned int index)
{
	Sound* const sound = &sounds[index];

	if (sound->buffer != NULL)
	{
		sound->position = 0;
		sound->playing = cc_true;
	}
}

void Sound_ReadFrames(void* const buffer_void, const size_t frames_to_read)
{
	int16_t* const buffer = (int16_t*)buffer_void;

	/* TODO: Handle return value. */
//	if (music_playing)
//		libvgmstream_fill(state, buffer, frames_to_read);
//	else
		memset(buffer, 0, frames_to_read * SOUND_CHANNELS * sizeof(int16_t));

	for (size_t sound_index = 0; sound_index < COUNT_OF(sounds); ++sound_index)
	{
		Sound* const sound = &sounds[sound_index];

		if (sound->playing)
		{
			const size_t frames_to_do = CC_MIN(frames_to_read, sound->length - sound->position);

			for (size_t frame_index = 0; frame_index < frames_to_do; ++frame_index)
			{
				const int16_t sample = sound->buffer[sound->position + frame_index];
				buffer[frame_index * 2 + 0] += sample;
				buffer[frame_index * 2 + 1] += sample;
			}

			sound->position += frames_to_do;

			if (sound->position == sound->length)
				sound->playing = cc_false;
		}
	}
}
