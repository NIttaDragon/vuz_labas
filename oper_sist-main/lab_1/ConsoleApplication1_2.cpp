#include <iostream>
#include <windows.h>
#include <thread>

using namespace std;

DWORD WINAPI myThread(LPVOID lpParametr)
{
	for (int i = 0; i < 10; i++) {
		cout << "Tread ID = " << this_thread::get_id() << "\tmain  " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	return 0;
}

int main(int argc, char* argv[])
{
	DWORD myThreadID;
	cout << "Start Thread" << endl;
	HANDLE myHandle;
	myHandle = CreateThread(NULL, 0, myThread, NULL, 0, &myThreadID);
	if (myHandle != NULL) {
		cout << "Create Thread Successfully" << endl;
		WaitForSingleObject(myHandle, INFINITE);
		cout << "Stop Thread" << endl;
		CloseHandle(myHandle);
	}
	else
		cout << "Error while Creating Thread" << endl;
	return 0;
}
