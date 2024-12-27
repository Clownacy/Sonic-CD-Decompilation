#include "audio.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "cmp.h"
#include "constants.h"
#include "pcminfo.h"
#include "soundchannel.h"
#include "util.h"
static void fill_audio_buffer(void* userdata, unsigned char* stream, int length);

static unsigned char* gp_sound_data = 0;
static pcm_info g_sounds[AUDIO_SOUNDS] = { 0 };
static sound_channel g_channels[6] = { 0 };


int init_audio() {
  int ret = 0;
  SDL_AudioSpec spec;

  spec.freq = 22050;
  spec.format = AUDIO_S16;
  spec.channels = 1;
  spec.samples = 512;
  spec.callback = fill_audio_buffer;
  spec.userdata = 0;
  if (SDL_OpenAudio(&spec, 0) < 0) {
    ret = 1;
  }

  return 0;
}


int load_sounds() {
  int ret = 0;
  FILE* fp = fopen("PCM.CMP", "rb");
  if (fp == 0) {
    ret = 1;
  }
  else {
    unsigned char buffer[16];
    cmp_header header;
    unsigned long pcm_data_size = 0;
    int i;

    fread(buffer, 1, 16, fp);
    read_cmp_header(buffer, &header);

    for (i = 0; i < AUDIO_SOUNDS; ++i) {
      fread(buffer, 1, 4, fp);
      read_ulong_littleendian(buffer, &g_sounds[i].size);
      pcm_data_size += g_sounds[i].size;
    }

    gp_sound_data = malloc(pcm_data_size);
    if (gp_sound_data == 0) {
      ret = 2;
    }
    else {
      unsigned char* p_data = gp_sound_data;

      for (i = 0; i < AUDIO_SOUNDS; ++i) {
        fread(p_data, 1, g_sounds[i].size, fp);
        g_sounds[i].p_data = p_data;
        p_data += g_sounds[i].size;
      }

      for (i = 0; i < AUDIO_SOUND_CHANNELS; ++i) {
        g_channels[i].id = -1;
      }

      SDL_PauseAudio(0);
    }
  }

  return ret;
}


static void fill_audio_buffer(void* userdata, unsigned char* stream, int length) {
  int i;

  for (i = 0; i < AUDIO_SOUND_CHANNELS; ++i) {
    if (g_channels[i].id != -1) {
      pcm_info info = g_sounds[g_channels[i].id];
      long remaining = info.size - g_channels[i].offset;

      if (length >= remaining) {
        length = remaining;
        g_channels[i].id = -1;
      }
      SDL_MixAudio(stream, &info.p_data[g_channels[i].offset], length, SDL_MIX_MAXVOLUME);
      g_channels[i].offset += length;
    }
  }
}


void WaveRequest(short ReqNo) {
  int i;

  for (i = 0; i < AUDIO_SOUND_CHANNELS; ++i) {
    if (g_channels[i].id == -1) {
      g_channels[i].id = ReqNo;
      g_channels[i].offset = 0;
      break;
    }
  }
}
