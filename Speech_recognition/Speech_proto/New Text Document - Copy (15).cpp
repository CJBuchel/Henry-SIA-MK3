case IDC_STOP:
        {

            _fcloseall();
            EnableWindow (RecButton, TRUE) ;
            EnableWindow (StpButton, FALSE) ;
            EnableWindow (PlyButton, TRUE);
            bEnding = TRUE ;
            SaveWavFile("temp.wav",pWaveHdr1);

        }
