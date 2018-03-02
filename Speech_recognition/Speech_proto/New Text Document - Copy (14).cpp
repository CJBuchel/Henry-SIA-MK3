case IDC_RECORD:
       {
           EnableWindow (RecButton, FALSE) ;
           EnableWindow (PlyButton, FALSE) ;
           EnableWindow (StpButton, TRUE)  ;
           waveOutReset (hWaveOut) ;
           waveInReset (hWaveIn) ;
           pBuffer1=reinterpret_cast <PBYTE> (malloc(INP_BUFFER_SIZE) );
           pBuffer2= reinterpret_cast <PBYTE> ( malloc(INP_BUFFER_SIZE) );

           if (!pBuffer1 || !pBuffer2)
           {
               if (pBuffer1) free (pBuffer1) ;
               if (pBuffer2) free (pBuffer2) ;
               MessageBox (hwnd, szMemError, szAppName,
                           MB_ICONEXCLAMATION | MB_OK) ;
               return TRUE ;
           }
           // Open waveform audio for input

           waveform.wFormatTag      = WAVE_FORMAT_PCM ;
           waveform.nChannels       = 1 ;
           waveform.nSamplesPerSec  = 11025 ;
           waveform.nAvgBytesPerSec = 11025 ;
           waveform.nBlockAlign     = 1 ;
           waveform.wBitsPerSample  = 8 ;
           waveform.cbSize          = 0 ;

           if (waveInOpen (&hWaveIn, WAVE_MAPPER, &waveform,
                           (DWORD) hwnd, 0, CALLBACK_WINDOW))
           {
               free (pBuffer1) ;
               free (pBuffer2) ;
           }
           // Set up headers and prepare them

           pWaveHdr1->lpData          =reinterpret_cast <CHAR*>( pBuffer1 ) ;
           pWaveHdr1->dwBufferLength  = INP_BUFFER_SIZE ;
           pWaveHdr1->dwBytesRecorded = 0 ;
           pWaveHdr1->dwUser          = 0 ;
           pWaveHdr1->dwFlags         = 0 ;
           pWaveHdr1->dwLoops         = 1 ;
           pWaveHdr1->lpNext          = NULL ;
           pWaveHdr1->reserved        = 0 ;

           waveInPrepareHeader (hWaveIn, pWaveHdr1, sizeof (WAVEHDR)) ;

           pWaveHdr2->lpData          = reinterpret_cast <CHAR*>(pBuffer2 ) ;
           pWaveHdr2->dwBufferLength  = INP_BUFFER_SIZE ;
           pWaveHdr2->dwBytesRecorded = 0 ;
           pWaveHdr2->dwUser          = 0 ;
           pWaveHdr2->dwFlags         = 0 ;
           pWaveHdr2->dwLoops         = 1 ;
           pWaveHdr2->lpNext          = NULL ;
           pWaveHdr2->reserved        = 0 ;

           waveInPrepareHeader (hWaveIn, pWaveHdr2, sizeof (WAVEHDR)) ;
       }
       break ;
