case MM_WIM_DATA:

        // Reallocate save buffer memory

        pNewBuffer = reinterpret_cast <PBYTE> (realloc (pSaveBuffer, dwDataLength +
                                               ((PWAVEHDR) lParam)->dwBytesRecorded)) ;

        if (pNewBuffer == NULL)
        {
            waveInClose (hWaveIn) ;

            MessageBox (hwnd, szMemError, szAppName,
                        MB_ICONEXCLAMATION | MB_OK) ;
            return TRUE ;
        }

        pSaveBuffer = pNewBuffer ;
        CopyMemory (pSaveBuffer + dwDataLength, ((PWAVEHDR) lParam)->lpData,
                    ((PWAVEHDR) lParam)->dwBytesRecorded) ;

        dwDataLength += ((PWAVEHDR) lParam)->dwBytesRecorded ;

        if (bEnding)
        {
            waveInClose (hWaveIn) ;
            return TRUE ;
        }

        // Send out a new buffer

        waveInAddBuffer (hWaveIn, (PWAVEHDR) lParam, sizeof (WAVEHDR)) ;
        return TRUE ;
