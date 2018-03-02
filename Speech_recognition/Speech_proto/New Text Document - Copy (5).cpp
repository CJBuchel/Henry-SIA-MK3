//start of wave visualisation process

int readSample(int number,bool leftchannel)
{

    /*
      Reads sample number, returns it as an int, if
      this.mono==false we look at the leftchannel bool
      to determine which to return.

      number is in the range [0,length/byte_samp]

      returns 0xefffffff on failure
    */

    if (number>=0 && number<length/byte_samp)
    {
        // go to beginning of the file
        rewind(stream);

        // we start reading at sample_number * sample_size + header length
        int offset = number * 1 + 44;

        // unless this is a stereo file and the rightchannel is requested.
        if (!mono && !leftchannel)
        {
        offset += byte_samp/2;
        }

        // read this many bytes;
        int amount;
        amount=byte_samp;

        fseek(stream,offset,SEEK_CUR);
        short sample = 0;
        fread((void *)&sample,1,amount,stream);

        return sample;
    }
    else
    {
        // return 0xefffffff if failed
        return (int)0xefffffff;
    }
}
s
