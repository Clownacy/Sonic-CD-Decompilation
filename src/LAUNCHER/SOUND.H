#ifndef SOUND_H
#define SOUND_H

#include <stddef.h>

#include "COMMON.H"

#define SOUND_CHANNELS 2

cc_bool Sound_Initialise(void);
void Sound_Deinitialise(void);

cc_bool Sound_PlayMusic(const char *file_path, unsigned int index, cc_bool loop);
void Sound_PlaySound(unsigned int index);

void Sound_ReadFrames(void* const buffer, const size_t frames_to_read);

#endif /* SOUND_H */
