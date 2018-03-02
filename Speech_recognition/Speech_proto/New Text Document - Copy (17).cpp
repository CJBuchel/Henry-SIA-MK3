void SaveWavFile(char *FileName, PWAVEHDR WaveHeader)
{
    fstream myFile (FileName, fstream::out | fstream::binary);

    int chunksize,pcmsize,NumSamples,subchunk1size;
    int audioFormat = 1;
    int numChannels = 1;
    int bitsPerSample = 8;



    NumSamples = ((long) (NUMPTS/sampleRate) * 1000);
    pcmsize = sizeof(PCMWAVEFORMAT);


    subchunk1size= 16;
    int byteRate = sampleRate*numChannels*bitsPerSample/8;
    int blockAlign = numChannels*bitsPerSample/8;
    int subchunk2size = WaveHeader->dwBufferLength*numChannels;
    chunksize = (36 + subchunk2size);
    // write the wav file per the wav file format
    myFile.seekp (0, ios::beg);
    myFile.write ("RIFF", 4);					// chunk id
    myFile.write ((char*) &chunksize, 4);	        	// chunk size (36 + SubChunk2Size))
    myFile.write ("WAVE", 4);					// format
    myFile.write ("fmt ", 4);					// subchunk1ID
    myFile.write ((char*) &subchunk1size, 4);			// subchunk1size (16 for PCM)
    myFile.write ((char*) &audioFormat, 2);			// AudioFormat (1 for PCM)
    myFile.write ((char*) &numChannels, 2);			// NumChannels
    myFile.write ((char*) &sampleRate, 4);			// sample rate
    myFile.write ((char*) &byteRate, 4);			// byte rate (SampleRate * NumChannels * BitsPerSample/8)
    myFile.write ((char*) &blockAlign, 2);			// block align (NumChannels * BitsPerSample/8)
    myFile.write ((char*) &bitsPerSample, 2);			// bits per sample
    myFile.write ("data", 4);					// subchunk2ID
    myFile.write ((char*) &subchunk2size, 4);			// subchunk2size (NumSamples * NumChannels * BitsPerSample/8)

    myFile.write (WaveHeader->lpData,WaveHeader->dwBufferLength);	// data
    myFile.close();
}
