case WM_PAINT:
        PAINTSTRUCT 	ps;
        hDC = BeginPaint(hwnd, &ps);

        if (hDC)
        {
            RECT rc;
            rc.top = 35;
			rc.left = 0;
			rc.bottom = 145;
			rc.right = 425;
			FillRect(hDC,&rc,(HBRUSH)(COLOR_WINDOW+2));
            if (PLAY==TRUE)
            {
		FillRect(hDC,&rc,(HBRUSH)(COLOR_WINDOW+2));
                hPen = CreatePen(PS_SOLID,1,RGB(0,200,0));
                SelectObject(hDC, hPen);

                SetMapMode(hDC, MM_ISOTROPIC);
                SetWindowExtEx(hDC, 400, 300, NULL);
                SetViewportExtEx(hDC,200, 180, NULL);
                SetViewportOrgEx(hDC, 0, 0, NULL);

                int sample=0;
                int i=1;
                int num = 60000;
                sample= readSample(i, TRUE);
                // scale the sample

                pt[i].x =i/20;
                pt[i].y = (int) ((sample)*1.5);
                MoveToEx (hDC,pt[i].x,pt[i].y,NULL);
                while (i<num && sample!=(int)0xefffffff)
                {
                    // scale the sample

                    pt[i].x = i/20;
                    pt[i].y = (int) ((sample)*1.5);

                    LineTo(hDC, pt[i].x,pt[i].y);
                    i++;
                    sample= readSample(i, TRUE);

                }


            }
            DeleteObject(hPen);
            DeleteDC(hDC);

			EndPaint(hwnd, &ps);

        }
        return 0;
