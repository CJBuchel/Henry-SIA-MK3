case WM_COMMAND:

        switch (wParam)
        {


        case APP_SAVE:
        {

            char szFileName[MAX_PATH] = "";
            OPENFILENAME ofn;
            ZeroMemory(&ofn, sizeof(ofn));

            ofn.lStructSize= sizeof(ofn);
            ofn.hwndOwner = hwnd;
            ofn.lpstrFilter = "Wave Files(*.wav)\0*.wav\0";
            ofn.lpstrFile = szFileName;
            ofn.nMaxFile = MAX_PATH;
            ofn.Flags = OFN_EXPLORER | OFN_OVERWRITEPROMPT;
            ofn.lpstrDefExt = "wav";
            if (GetSaveFileName(&ofn))
            {
                if (szFileName)
                {
                    SaveWavFile(szFileName,pWaveHdr1);
                }
            }
        }
        break ;
