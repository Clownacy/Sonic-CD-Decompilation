#include "SOUND.H"

#include "vgmstream/src/libvgmstream.h"

static libvgmstream_t* state;
static cc_bool music_playing;

cc_bool Sound_Initialise(void)
{
	state = libvgmstream_init();
	return state != NULL;
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

size_t Sound_ReadMusic(void* const buffer, const size_t frames_to_read)
{
	if (!music_playing)
		return 0;

	/* TODO: Handle return value. */
	libvgmstream_fill(state, buffer, frames_to_read);

	return frames_to_read;
}
