case MM_WIM_CLOSE:
        // Free the buffer memory

        waveInUnprepareHeader (hWaveIn, pWaveHdr1, sizeof (WAVEHDR)) ;
        waveInUnprepareHeader (hWaveIn, pWaveHdr2, sizeof (WAVEHDR)) ;

        free (pBuffer1) ;
        free (pBuffer2) ;

        // Enable and disable buttons
        if (dwDataLength > 0)
        {
            EnableWindow (PlyButton,   TRUE)  ;
        }
        bRecording = FALSE ;

        if (bTerminating)
            SendMessage (hwnd, WM_SYSCOMMAND, SC_CLOSE, 0L) ;

        return TRUE
