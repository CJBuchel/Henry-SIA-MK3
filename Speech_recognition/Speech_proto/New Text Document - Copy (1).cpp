#include <CommDlg.h>
#include <MMSystem.h>
#include <fstream>
#include <cstdlib>
#include "resource.h"

using namespace std;
//Globals for sound wave visualistion
int number, length, byte_samp, byte_sec, bit_samp;
static int sampleRate = 11025;
const int NUMPTS = 11025 * 10;
bool mono = TRUE;
bool PLAY = FALSE;
errno_t wavfile;
char * filename;
int s_rate = 11025;
double limit = 10000.0;
FILE * stream;
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
/* Declare procedures */
int readSample(int number,bool leftchannel);
void SaveWavFile(char *FileName, PWAVEHDR WaveHeader);
void Wav(char *c, HWND hWnd);
/*  Make the class name into a global variable  */
char szAppName[ ] = "Recorder";
