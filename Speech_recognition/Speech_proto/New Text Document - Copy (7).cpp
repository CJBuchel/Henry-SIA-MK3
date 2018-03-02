case MM_WIM_OPEN:
        // Shrink down the save buffer

        pSaveBuffer = reinterpret_cast <PBYTE>(realloc (pSaveBuffer, 1)) ;




        // Add the buffers

        waveInAddBuffer (hWaveIn, pWaveHdr1, sizeof (WAVEHDR)) ;
        waveInAddBuffer (hWaveIn, pWaveHdr2, sizeof (WAVEHDR)) ;

        // Begin sampling

        bRecording = TRUE ;
        bEnding = FALSE ;
        dwDataLength = 0 ;
        waveInStart (hWaveIn) ;
        return TRUE ;
