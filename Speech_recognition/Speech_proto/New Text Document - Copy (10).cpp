case MM_WOM_OPEN:

        // Set up header

        pWaveHdr1->lpData          = reinterpret_cast <CHAR*>(pSaveBuffer) ;
        pWaveHdr1->dwBufferLength  = dwDataLength ;
        pWaveHdr1->dwBytesRecorded = 0 ;
        pWaveHdr1->dwUser          = 0 ;
        pWaveHdr1->dwFlags         = WHDR_BEGINLOOP | WHDR_ENDLOOP ;
        pWaveHdr1->dwLoops         = dwRepetitions ;
        pWaveHdr1->lpNext          = NULL ;
        pWaveHdr1->reserved        = 0 ;

        // Prepare and write

        waveOutPrepareHeader (hWaveOut, pWaveHdr1, sizeof (WAVEHDR)) ;
        waveOutWrite (hWaveOut, pWaveHdr1, sizeof (WAVEHDR)) ;

        bEnding = FALSE ;
        bPlaying = TRUE ;
        return TRUE ;
