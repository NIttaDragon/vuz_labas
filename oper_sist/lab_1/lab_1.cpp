#include <windows.h>
#include <iostream>
using namespace std;
int main()
{
    //указываем путь к файлу, который будем открывать
    TCHAR szPath[] = TEXT("C:\\Users\\uspem\\source\\repos\\ConsoleApplication1\\x64\\Debug\\ConsoleApplication1.exe");
    //создаём процесс
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    cout << "Start ConsoleApplication1.exe" << endl;
    // Запускаем процесс
    CreateProcess(NULL, szPath, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi); 
    // Ожидаем завершения процесса
    WaitForSingleObject(pi.hProcess, INFINITE);  // Ожидаем завершения процесса
    cout << "Stop ConsoleApplication1.exe" << endl;
    // Закрываем дескрипторы процесса и потока
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}
