case IDC_PLAY:
       {
           // play wav file
           bPlaying = TRUE;

           EnableWindow (PlyButton, FALSE);
           waveform.wFormatTag      = WAVE_FORMAT_PCM ;
           waveform.nChannels       = 1 ;
           waveform.nSamplesPerSec  = 11025 ;
           waveform.nAvgBytesPerSec = 11025 ;
           waveform.nBlockAlign     = 1 ;
           waveform.wBitsPerSample  = 8 ;
           waveform.cbSize          = 0 ;
           waveInReset (hWaveIn) ;
           waveOutReset (hWaveOut) ;
           if (waveOutOpen (&hWaveOut, WAVE_MAPPER, &waveform,
                            (DWORD) hwnd, 0, CALLBACK_WINDOW))
           {

               MessageBox (hwnd, szOpenError, szAppName,
                           MB_ICONEXCLAMATION | MB_OK) ;
           }





           Wav("temp.wav", hwnd);




           RECT rc;
           GetClientRect(hwnd, &rc);
           PLAY = TRUE;
           InvalidateRect(hwnd,&rc,TRUE);
       }
       break ;
       }
       break ;
