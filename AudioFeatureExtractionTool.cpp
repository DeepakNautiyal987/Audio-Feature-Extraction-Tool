#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;
int PassError(char *msg)
{
	cout << "Error Caught" << endl;
	getchar();
	return 0;
}
void main()
{
	PlaySound(TEXT("Audio File Name Here"), NULL, SND_SYNC);
	FILE *fp = NULL;
	fp = fopen("Audio File Name here", "r");
	char Type[4];
	DWORD Size, ChunkSize, DataSize;
	short Channel, FormatType, BytesPerSample, BitsPerSample;
	DWORD AvgBytesPerSec, SampleRate;
	fread(Type, sizeof(char), 4, fp);
	if (!fp)
	{
		PassError("");
	}
	if (!strcmp(Type, "RIFF"))
	{
		PassError("");
	}
	fread(&Size, sizeof(DWORD), 1, fp);
	fread(Type, sizeof(char), 4, fp);
	if (!strcmp(Type, "WAVE"))
	{
		PassError("");
	}
	fread(Type, sizeof(char), 4, fp);
	if (!strcmp(Type, "fmt"))
	{
		PassError("");
	}
	fread(&ChunkSize, sizeof(DWORD), 1, fp);
	fread(&FormatType, sizeof(short), 1, fp);
	fread(&Channel, sizeof(short), 1, fp);
	fread(&SampleRate, sizeof(DWORD), 1, fp);
	fread(&AvgBytesPerSec, sizeof(DWORD), 1, fp);
	fread(&BytesPerSample, sizeof(short), 1, fp);
	fread(&BitsPerSample, sizeof(short), 1, fp);
	fread(Type, sizeof(char), 4, fp);
	if (!strcmp(Type, "data"))
	{
		PassError("");
	}
	fread(&DataSize, sizeof(DWORD), 1, fp);
	cout << "chunk size:" << ChunkSize <<endl;
	cout << "Channels: " <<Channel <<endl;
	cout << "Format Type: " <<FormatType << endl;
	cout << "Sample rate: " <<SampleRate << endl;
	cout << "Avg Bytes Per Sec: " <<AvgBytesPerSec << endl;
	cout << "Bytes Per Sample: " <<BytesPerSample << endl;
	cout << "Bits Per Sample: " <<BitsPerSample << endl;
	getchar();
}