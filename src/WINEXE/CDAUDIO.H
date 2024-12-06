#ifndef CDAUDIO_H
#define CDAUDIO_H

MCIERROR cdAudio_open(LPSTR errMsg, ULONG msgSize);
void cdAudio_close();
MCIERROR cdAudio_getMciMode(ULONG* mciMode);
MCIERROR cdAudio_switchTrack(long trackId, BOOL bUnknown, HWND hWnd);
MCIERROR cdAudio_playIfStopped();
MCIERROR cdAudio_stop();
MCIERROR cdAudio_playIfNotStopped(HWND hWnd);

#endif
