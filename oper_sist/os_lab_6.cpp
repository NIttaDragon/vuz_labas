#include <Windows.h>
#include <iostream>
#include <time.h>
#include <string>
#include <random>

using namespace std;

void RandNum(int kol) // ”ã­ªæ¨ï ¤«ï ¢ëç¨á«¥­¨ï á«ãç ©­ëå ¤ ­­ëå
{
  int sum;
  for (int i = 0; i < kol; ++i)
    sum += rand();
}

void SyncOpr(const string& filename, size_t bufferSize, int num) // ”ã­ªæ¨ï ¤«ï á¨­åà®­­®© § ¯¨á¨ ¢ ä ©«
{
    HANDLE fileHandle = CreateFileA(filename.c_str(), // ˆ¬ï á®§¤ ¢ ¥¬®£® ¨«¨ ®âªàë¢ ¥¬®£® ä ©«  ¨«¨ ãáâà®©áâ¢ 
                                    GENERIC_WRITE, // ‡ ¯à®è¥­­ë© ¤®áâã¯ ª ä ©«ã ¨«¨ ãáâà®©áâ¢ã
                                    FILE_SHARE_READ, // ‡ ¯à®è¥­­ë© à¥¦¨¬ ®¡é¥£® ¤®áâã¯  ª ä ©«ã ¨«¨ ãáâà®©áâ¢ã
                                    nullptr, // “ª § â¥«ì ­  áâàãªâãàã ¡¥§®¯ á­®áâ¨
                                    CREATE_ALWAYS, // „¥©áâ¢¨¥, ¢ë¯®«­ï¥¬®¥ á ä ©«®¬ ¨«¨ ãáâà®©áâ¢®¬
                                    FILE_ATTRIBUTE_NORMAL, // €âà¨¡ãâë ¨ ä« £¨ ä ©«  ¨«¨ ãáâà®©áâ¢ 
                                    nullptr); // „®¯ãáâ¨¬ë© ¤¥áªà¨¯â®à ä ©«  è ¡«®­ 
    cout<<"Žâªàëâ¨¥ ä ©«  ¢ á¨­åà®­­®¬ à¥¦¨¬¥"<<endl;
    if (fileHandle == INVALID_HANDLE_VALUE) {
        cout << "¥¢®§¬®¦­® ®âªàëâì ä ©«" << endl;
        return;
    }
    char* buffer = new char[bufferSize]; // ‘®§¤ ­¨¥ ¡ãä¥à 
    cout<<"‡ ¯®«­¥­¨¥ ä ©«  á«ãç ©­ë¬¨ §­ ç¥­¨ï¬¨"<<endl;
    for (int i = 0; i < bufferSize; ++i)
        buffer[i] = rand();

    // ‡ ¯¨áì ¢ ä ©«
    DWORD bytesWritten;
    for (int i = 0; i < num; ++i){
        if (!WriteFile(fileHandle, buffer, bufferSize, &bytesWritten, nullptr)) {
            cout << "Žè¨¡ª  § ¯¨á¨ ¢ ä ©«" << endl;
            break;
        }
        // cout << "‡ ¯¨á ­® " << bytesWritten << " ¡ ©â" << endl;
      }
    // ‡ ªàëâ¨¥ ä ©« 
    CloseHandle(fileHandle);
    delete[] buffer;
}


void AsyncOpr(const string& filename, size_t bufferSize, int num) // ”ã­ªæ¨ï ¤«ï  á¨­åà®­­®© § ¯¨á¨ ¢ ä ©«
{
    HANDLE fileHandle = CreateFileA(filename.c_str(), // ˆ¬ï á®§¤ ¢ ¥¬®£® ¨«¨ ®âªàë¢ ¥¬®£® ä ©«  ¨«¨ ãáâà®©áâ¢ 
                                    GENERIC_WRITE, // ‡ ¯à®è¥­­ë© ¤®áâã¯ ª ä ©«ã ¨«¨ ãáâà®©áâ¢ã
                                    FILE_SHARE_READ, // ‡ ¯à®è¥­­ë© à¥¦¨¬ ®¡é¥£® ¤®áâã¯  ª ä ©«ã ¨«¨ ãáâà®©áâ¢ã
                                    nullptr, // “ª § â¥«ì ­  áâàãªâãàã ¡¥§®¯ á­®áâ¨
                                    CREATE_ALWAYS, // „¥©áâ¢¨¥, ¢ë¯®«­ï¥¬®¥ á ä ©«®¬ ¨«¨ ãáâà®©áâ¢®¬
                                    FILE_ATTRIBUTE_NORMAL, // €âà¨¡ãâë ¨ ä« £¨ ä ©«  ¨«¨ ãáâà®©áâ¢ 
                                    nullptr); // „®¯ãáâ¨¬ë© ¤¥áªà¨¯â®à ä ©«  è ¡«®­ 
    cout<<"Žâªàëâ¨¥ ä ©«  ¢  á¨­åà®­­®¬ à¥¦¨¬¥"<<endl;
    if (fileHandle == INVALID_HANDLE_VALUE) {
        cout << "¥¢®§¬®¦­® ®âªàëâì ä ©«" << endl;
        return;
    }

    char* buffer = new char[bufferSize]; // ‘®§¤ ­¨¥ ¡ãä¥à 
    cout<<"‡ ¯®«­¥­¨¥ ä ©«  á«ãç ©­ë¬¨ §­ ç¥­¨ï¬¨"<<endl;
    for (int i = 0; i < bufferSize; ++i)
        buffer[i] = rand();

    // ‘®§¤ ­¨¥ ®¡ê¥ªâ  ¤«ï  á¨­åà®­­®© § ¯¨á¨
    OVERLAPPED overlapped;
    ZeroMemory(&overlapped, sizeof(overlapped));

    // €á¨­åà®­­ ï § ¯¨áì ¢ ä ©«
    DWORD bytesWritten;
    for (int i = 0; i < num; ++i) {
        if (!WriteFile(fileHandle, buffer, bufferSize, &bytesWritten, &overlapped)) {
            if (GetLastError() == ERROR_IO_PENDING) {
                if (WaitForSingleObject(overlapped.hEvent, INFINITE) != WAIT_OBJECT_0)
                    cout << "‚à¥¬ï ®¦¨¤ ­¨ï  áá¨­åà®­­®© § ¯¨á¨ ¢ëè«®" << endl;
                GetOverlappedResult(fileHandle, &overlapped, &bytesWritten, FALSE); // ®«ãç¥­¨¥ ª®«¨ç¥áâ¢  § ¯¨á ­­ëå ¡ ©â
                cout << "‚  á¨­åà®­­®¬ à¥¦¨¬¥ § ¯¨á ­® " << bytesWritten << " ¡ ©â" << endl;
            } else
                cout << "Žè¨¡ª  § ¯¨á¨ ¤ ­­ëå ¢  á¨­åà®­­®¬ à¥¦¨¬¥" << endl;
        }
    }

    // ‡ ªàëâ¨¥ ä ©« 
    CloseHandle(fileHandle);
    delete[] buffer;
}

int main() {
    string filename = "E:\\test.txt"; // ” ©« ­  ¤¨áª¥â¥
    int buffS[] = { 512, 1024, 2048, 4096 }; //  §¬¥àë ¡ãä¥à 
    int num = 10000; // Š®«¨ç¥áâ¢® ¨â¥à æ¨© ¤«ï ¢ëç¨á«¨â¥«ì­®© ¯à®æ¥¤ãàë

    for (int i=0; i<4; i++){
        cout << "\n §¬¥à ¡ãä¥à : " << buffS[i] << " ¡ ©â" << endl;
        clock_t start, end;
        cout<<"‡ ¯ãáª á¨­åà®­­®£® à¥¦¨¬ "<<endl; // ‘¨­åà®­­ ï § ¯¨áì
        start = clock();
        SyncOpr(filename, buffS[i], buffS[i] * 1024 / buffS[i]); // ‡ ¯¨áì 1000 Š¡
        end = clock();
        cout << "‚à¥¬ï § ¯¨á¨ ä ©«  á¨­åà®­­®¬ à¥¦¨¬¥: " << (double)(end - start) / CLOCKS_PER_SEC << " á¥ªã­¤" << endl;

        cout<<"‡ ¯ãáª ¢ëç¨á«¨â¥«ì­®© ¯à®æ¥¤ãàë"<<endl;
        start = clock();
        for (int j = 0; j < 1000; j++)
          RandNum(num);
        end = clock();
        cout<<"‡ ¢¥àè¥­¨¥ ¢ëç¨á«¨â¥«ì­®© ¯à®æ¥¤ãàë"<<endl;
        cout << "‚à¥¬ï ¢ëç¨á«¥­¨©: " << (double)(end - start) / CLOCKS_PER_SEC << " á¥ªã­¤" << endl;

        if (DeleteFileA(filename.c_str()))
            cout << "” ©« ã¤ «¥­" << endl;
        else
            cout << "¥ ã¤ «®áì ã¤ «¨âì ä ©«" << endl;

        cout<<"‡ ¯ãáª  á¨­åà®­­®£® à¥¦¨¬ "<<endl; // €á¨­åà®­­ ï § ¯¨áì
        start = clock();
        AsyncOpr(filename, buffS[i], buffS[i] * 1024 / buffS[i]); // ‡ ¯¨áì 1000 Š¡
        end = clock();
        cout << "‚à¥¬ï § ¯¨á¨ ä ©«  ¢  á¨­åà®­­®¬ à¥¦¨¬¥: " << (double)(end - start) / CLOCKS_PER_SEC << " á¥ªã­¤" << endl;
        cout<<"‡ ¯ãáª ¢ëç¨á«¨â¥«ì­®© ¯à®æ¥¤ãàë"<<endl;
        start = clock();
        for (int j = 0; j < 1000; j++)
          RandNum(num);
        end = clock();
        cout<<"‡ ¢¥àè¥­¨¥ ¢ëç¨á«¨â¥«ì­®© ¯à®æ¥¤ãàë"<<endl;
        cout << "‚à¥¬ï ¢ëç¨á«¥­¨©: " << (double)(end - start) / CLOCKS_PER_SEC << " á¥ªã­¤" << endl;
    }
    return 0;
}

/*
à §­¨æ  á¨­åà®­­®© ¨  áá¨­åà®­­®© - ¢ ¯ à ¬¥âà¥ overlapped (¢  áá¨­åà®­­®¬)
áâàãªâãà  overlapped ®â¢¥ç ¥â §  â® çâ®¡ë äã­ªæ¨ï ¢ë¯®«­ï« áì ¯®á«¥ ¤¥©áâ¢¨ï WaitForSigleObject,
â.¥. ¯®ª  ­¥ ¯à®¨§®©¤¥â ®¯à¥¤¥«¥­­®¥ ¤¥©áâ¢¨¥,  á¨­åà®­­ ï äã­ªæ¨ï ¡ã¤¥â ¯à®¨áâ ¨¢ âì
*/
