/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND RecButton;
    static HWND PlyButton;
    static HWND StpButton;
    static HMENU hMenu;
    static HPEN hPen;
    static BOOL         bRecording, bPlaying,bEnding, bTerminating ;
    static DWORD        dwDataLength, dwRepetitions = 1 ;
    static HWAVEIN      hWaveIn ;
    static HWAVEOUT     hWaveOut ;
    static PBYTE        pBuffer1, pBuffer2, pSaveBuffer, pNewBuffer ;
    static PWAVEHDR     pWaveHdr1, pWaveHdr2 ;
    static TCHAR        szOpenError[] = TEXT ("Error opening waveform audio!");
    static TCHAR        szMemError [] = TEXT ("Error allocating memory!") ;
    static WAVEFORMATEX waveform ;

    hMenu = GetMenu (hwnd);
    HDC hDC;
    POINT pt [NUM];
    BOOL fSuccess = FALSE;

    switch (message)                  /* handle the messages */
    {
    case WM_CREATE:
        RecButton = CreateWindow ( TEXT ("button"),"RECORD",WS_VISIBLE|WS_CHILD|ES_LEFT|1,7,175,100,25,hwnd,(HMENU) IDC_RECORD,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
        PlyButton = CreateWindow ( TEXT ("button"),"PLAY",WS_VISIBLE|WS_CHILD|ES_LEFT|1,157,175,100,25,hwnd,(HMENU) IDC_PLAY,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
        StpButton = CreateWindow ( TEXT ("button"),"STOP",WS_VISIBLE|WS_CHILD|ES_LEFT|1,314,175,100,25,hwnd,(HMENU) IDC_STOP,((LPCREATESTRUCT) lParam) -> hInstance,NULL);
        EnableWindow (PlyButton, FALSE) ;
        EnableWindow (StpButton, FALSE)  ;

        pWaveHdr1 =  reinterpret_cast <PWAVEHDR> ( malloc (sizeof (WAVEHDR)) );
        pWaveHdr2 = reinterpret_cast <PWAVEHDR> ( malloc (sizeof (WAVEHDR)) ) ;
        // Allocate memory for save buffer

        pSaveBuffer = reinterpret_cast <PBYTE> ( malloc (1) ) ;

        return 0;
