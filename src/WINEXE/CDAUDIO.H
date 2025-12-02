#ifndef CDAUDIO_H
#define CDAUDIO_H

MCIERROR cdAudio_open(LPSTR errMsg, ULONG msgSize);
void cdAudio_close(void);
MCIERROR cdAudio_getMciMode(ULONG* mciMode);
MCIERROR cdAudio_switchTrack(long trackId, BOOL bUnknown, HWND hWnd);
MCIERROR cdAudio_playIfStopped(void);
MCIERROR cdAudio_stop(void);
MCIERROR cdAudio_playIfNotStopped(HWND hWnd);

#endif
