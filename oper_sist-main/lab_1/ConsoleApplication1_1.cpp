#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

using namespace std;

DWORD WINAPI myThread(LPVOID lpParametr)
{
	unsigned int& myCounter = *((unsigned int*)lpParametr);
	while (myCounter < 0xFFFFFFFF) ++myCounter;
	return 0;
}

int main(int argc, char* argv[])
{
	unsigned int myCounter = 0;
	DWORD myThreadID;
	HANDLE myHandle = CreateThread(0, 0, myThread, &myCounter, 0, &myThreadID);
	char myChar = ' ';
	while (myChar != 'q')
	{
		cout << myCounter << endl;
		myChar = getchar();
	}

	CloseHandle(myHandle);
	return 0;
}
