// Read the temporary wav file
void Wav(char *c, HWND hWnd)
{

    filename = new char[strlen(c)+1];
    strcpy_s(filename,strlen(c)+1,c);
    // open filepointer readonly
    wavfile = fopen_s(&stream,filename,"r");
    if (stream==NULL)
    {
        MessageBox(hWnd, "Could not open " + (char)filename,"Error", MB_OK);

    }
    else
    {
        // declare a char buff to store some values in
        char *buff = new char[5];
        buff[4]='\0';
        // read the first 4 bytes
        fread((void *)buff,1,4,stream);
        // the first four bytes should be 'RIFF'
        if (strcmp((char *)buff,"RIFF")==0)
        {

            // read byte 8,9,10 and 11
            fseek(stream,4,SEEK_CUR);
            fread((void *)buff,1,4,stream);
            // this should read "WAVE"
            if (strcmp((char *)buff,"WAVE")==0)
            {
                // read byte 12,13,14,15
                fread((void *)buff,1,4,stream);
                // this should read "fmt "
                if (strcmp((char *)buff,"fmt ")==0)
                {
                    fseek(stream,20,SEEK_CUR);
                    // final one read byte 36,37,38,39
                    fread((void *)buff,1,4,stream);
                    if (strcmp((char *)buff,"data")==0)
                    {


                        // Now we know it is a wav file, rewind the stream
                        rewind(stream);
                        // now is it mono or stereo ?
                        fseek(stream,22,SEEK_CUR);
                        fread((void *)buff,1,2,stream);
                        if (buff[0]==0x02)
                        {
                            mono=false;
                        }
                        else
                        {
                            mono=true;
                        }
                        // read the sample rate
                        fread((void *)&s_rate,1,4,stream);
                        fread((void *)&byte_sec,1,4,stream);
                        byte_samp=0;
                        fread((void *)&byte_samp,1,2,stream);
                        bit_samp=0;
                        fread((void *)&bit_samp,1,2,stream);
                        fseek(stream,4,SEEK_CUR);
                        fread((void *)&length,1,4,stream);
                    }
                }
            }
        }
        delete buff;

    }
}
