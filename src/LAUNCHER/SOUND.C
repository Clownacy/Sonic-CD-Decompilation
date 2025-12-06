#include "SOUND.H"

#include <stdlib.h>
#include <string.h>

#include "SDL.h"

#include "vgmstream/src/libvgmstream.h"

typedef struct Sound
{
	float *buffer;
	size_t length, position;
	cc_bool playing;
} Sound;

static libvgmstream_t* state;
static cc_bool music_playing, ring_flip_flop;

static Sound sounds[0x80];

cc_bool Sound_Initialise(void)
{
	state = libvgmstream_init();

	if (state != NULL)
	{
		libstreamfile_t* const file = libstreamfile_open_from_stdio("SE.ACX");

		if (file != NULL)
		{
			for (size_t i = 0; i < COUNT_OF(sounds); ++i)
			{
				libvgmstream_config_t config = {};
				config.auto_downmix_channels = SOUND_CHANNELS;
				config.force_sfmt = LIBVGMSTREAM_SFMT_FLOAT;
				libvgmstream_setup(state, &config);

				const int result = libvgmstream_open_stream(state, file, i + 1);

				if (result >= 0)
				{
					SDL_AudioStream* const converter = SDL_NewAudioStream(
						AUDIO_F32SYS, state->format->channels, state->format->sample_rate,
						AUDIO_F32SYS, SOUND_CHANNELS, SOUND_SAMPLE_RATE);

					if (converter != NULL)
					{
						while (!state->decoder->done)
						{
							libvgmstream_render(state);
							SDL_AudioStreamPut(converter, state->decoder->buf, state->decoder->buf_bytes);
						}

						libvgmstream_close_stream(state);
						SDL_AudioStreamFlush(converter);

						const int total_bytes = SDL_AudioStreamAvailable(converter);

						sounds[i].buffer = (float*)malloc(total_bytes);

						if (sounds[i].buffer != NULL)
						{
							sounds[i].length = total_bytes / sizeof(float);
							sounds[i].position = 0;

							SDL_AudioStreamGet(converter, sounds[i].buffer, total_bytes);
						}

						SDL_FreeAudioStream(converter);
					}
				}
			}

			libstreamfile_close(file);

			return cc_true;
		}

		libvgmstream_free(state);
	}

	return cc_false;
}

void Sound_Deinitialise(void)
{
	for (size_t i = 0; i < COUNT_OF(sounds); ++i)
		free(sounds[i].buffer);

	libvgmstream_free(state);
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
		config.force_sfmt = LIBVGMSTREAM_SFMT_FLOAT;
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

void Sound_PlaySound(unsigned int index)
{
	if (index == 5)
	{
		if (ring_flip_flop)
			index = 22;

		ring_flip_flop = !ring_flip_flop;
	}

	Sound* const sound = &sounds[index];

	if (sound->buffer != NULL)
	{
		sound->position = 0;
		sound->playing = cc_true;
	}
}

void Sound_ReadFrames(void* const buffer_void, const size_t frames_to_read)
{
	float* const buffer = (float*)buffer_void;

	/* TODO: Handle return value. */
	if (music_playing)
	{
		libvgmstream_fill(state, buffer, frames_to_read);
	}
	else
	{
		for (size_t i = 0; i < frames_to_read * SOUND_CHANNELS; ++i)
			buffer[i] = 0.0f;
	}

	for (size_t sound_index = 0; sound_index < COUNT_OF(sounds); ++sound_index)
	{
		Sound* const sound = &sounds[sound_index];

		if (sound->playing)
		{
			const size_t samples_to_do = CC_MIN(frames_to_read * SOUND_CHANNELS, sound->length - sound->position);

			for (size_t sample_index = 0; sample_index < samples_to_do; ++sample_index)
				buffer[sample_index] += sound->buffer[sound->position + sample_index];

			sound->position += samples_to_do;

			if (sound->position == sound->length)
				sound->playing = cc_false;
		}
	}
}
