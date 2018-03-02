case MM_WOM_DONE:

       waveOutUnprepareHeader (hWaveOut, pWaveHdr1, sizeof (WAVEHDR)) ;
       waveOutClose (hWaveOut) ;
       EnableWindow (PlyButton, TRUE);
       return TRUE ;

   case MM_WOM_CLOSE:

       dwRepetitions = 1 ;
       bPlaying = FALSE ;

       return TRUE ;
