case APP_EXIT:
       {
           PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
           //cleanup before closing
           _fcloseall();
           fSuccess= DeleteFile(TEXT("temp.wav"));
       }
       break ;
