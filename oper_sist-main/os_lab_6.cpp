#include <Windows.h>
#include <iostream>
#include <time.h>
#include <string>
#include <random>

using namespace std;

void RandNum(int kol) // �㭪�� ��� ���᫥��� ��砩��� ������
{
  int sum;
  for (int i = 0; i < kol; ++i)
    sum += rand();
}

void SyncOpr(const string& filename, size_t bufferSize, int num) // �㭪�� ��� ᨭ�஭��� ����� � 䠩�
{
    HANDLE fileHandle = CreateFileA(filename.c_str(), // ��� ᮧ��������� ��� ���뢠����� 䠩�� ��� ���ன�⢠
                                    GENERIC_WRITE, // ����襭�� ����� � 䠩�� ��� ���ன���
                                    FILE_SHARE_READ, // ����襭�� ०�� ��饣� ����㯠 � 䠩�� ��� ���ன���
                                    nullptr, // �����⥫� �� �������� ������᭮��
                                    CREATE_ALWAYS, // ����⢨�, �믮��塞�� � 䠩��� ��� ���ன�⢮�
                                    FILE_ATTRIBUTE_NORMAL, // ��ਡ��� � 䫠�� 䠩�� ��� ���ன�⢠
                                    nullptr); // �����⨬� ���ਯ�� 䠩�� 蠡����
    cout<<"����⨥ 䠩�� � ᨭ�஭��� ०���"<<endl;
    if (fileHandle == INVALID_HANDLE_VALUE) {
        cout << "���������� ������ 䠩�" << endl;
        return;
    }
    char* buffer = new char[bufferSize]; // �������� ����
    cout<<"���������� 䠩�� ��砩�묨 ���祭�ﬨ"<<endl;
    for (int i = 0; i < bufferSize; ++i)
        buffer[i] = rand();

    // ������ � 䠩�
    DWORD bytesWritten;
    for (int i = 0; i < num; ++i){
        if (!WriteFile(fileHandle, buffer, bufferSize, &bytesWritten, nullptr)) {
            cout << "�訡�� ����� � 䠩�" << endl;
            break;
        }
        // cout << "����ᠭ� " << bytesWritten << " ����" << endl;
      }
    // �����⨥ 䠩��
    CloseHandle(fileHandle);
    delete[] buffer;
}


void AsyncOpr(const string& filename, size_t bufferSize, int num) // �㭪�� ��� �ᨭ�஭��� ����� � 䠩�
{
    HANDLE fileHandle = CreateFileA(filename.c_str(), // ��� ᮧ��������� ��� ���뢠����� 䠩�� ��� ���ன�⢠
                                    GENERIC_WRITE, // ����襭�� ����� � 䠩�� ��� ���ன���
                                    FILE_SHARE_READ, // ����襭�� ०�� ��饣� ����㯠 � 䠩�� ��� ���ன���
                                    nullptr, // �����⥫� �� �������� ������᭮��
                                    CREATE_ALWAYS, // ����⢨�, �믮��塞�� � 䠩��� ��� ���ன�⢮�
                                    FILE_ATTRIBUTE_NORMAL, // ��ਡ��� � 䫠�� 䠩�� ��� ���ன�⢠
                                    nullptr); // �����⨬� ���ਯ�� 䠩�� 蠡����
    cout<<"����⨥ 䠩�� � �ᨭ�஭��� ०���"<<endl;
    if (fileHandle == INVALID_HANDLE_VALUE) {
        cout << "���������� ������ 䠩�" << endl;
        return;
    }

    char* buffer = new char[bufferSize]; // �������� ����
    cout<<"���������� 䠩�� ��砩�묨 ���祭�ﬨ"<<endl;
    for (int i = 0; i < bufferSize; ++i)
        buffer[i] = rand();

    // �������� ��ꥪ� ��� �ᨭ�஭��� �����
    OVERLAPPED overlapped;
    ZeroMemory(&overlapped, sizeof(overlapped));

    // �ᨭ�஭��� ������ � 䠩�
    DWORD bytesWritten;
    for (int i = 0; i < num; ++i) {
        if (!WriteFile(fileHandle, buffer, bufferSize, &bytesWritten, &overlapped)) {
            if (GetLastError() == ERROR_IO_PENDING) {
                if (WaitForSingleObject(overlapped.hEvent, INFINITE) != WAIT_OBJECT_0)
                    cout << "�६� �������� ��ᨭ�஭��� ����� ��諮" << endl;
                GetOverlappedResult(fileHandle, &overlapped, &bytesWritten, FALSE); // ����祭�� ������⢠ ����ᠭ��� ����
                cout << "� �ᨭ�஭��� ०��� ����ᠭ� " << bytesWritten << " ����" << endl;
            } else
                cout << "�訡�� ����� ������ � �ᨭ�஭��� ०���" << endl;
        }
    }

    // �����⨥ 䠩��
    CloseHandle(fileHandle);
    delete[] buffer;
}

int main() {
    string filename = "E:\\test.txt"; // ���� �� ��᪥�
    int buffS[] = { 512, 1024, 2048, 4096 }; // ������� ����
    int num = 10000; // ������⢮ ���権 ��� ���᫨⥫쭮� ��楤���

    for (int i=0; i<4; i++){
        cout << "\n������ ����: " << buffS[i] << " ����" << endl;
        clock_t start, end;
        cout<<"����� ᨭ�஭���� ०���"<<endl; // ����஭��� ������
        start = clock();
        SyncOpr(filename, buffS[i], buffS[i] * 1024 / buffS[i]); // ������ 1000 ��
        end = clock();
        cout << "�६� ����� 䠩�� ᨭ�஭��� ०���: " << (double)(end - start) / CLOCKS_PER_SEC << " ᥪ㭤" << endl;

        cout<<"����� ���᫨⥫쭮� ��楤���"<<endl;
        start = clock();
        for (int j = 0; j < 1000; j++)
          RandNum(num);
        end = clock();
        cout<<"�����襭�� ���᫨⥫쭮� ��楤���"<<endl;
        cout << "�६� ���᫥���: " << (double)(end - start) / CLOCKS_PER_SEC << " ᥪ㭤" << endl;

        if (DeleteFileA(filename.c_str()))
            cout << "���� 㤠���" << endl;
        else
            cout << "�� 㤠���� 㤠���� 䠩�" << endl;

        cout<<"����� �ᨭ�஭���� ०���"<<endl; // �ᨭ�஭��� ������
        start = clock();
        AsyncOpr(filename, buffS[i], buffS[i] * 1024 / buffS[i]); // ������ 1000 ��
        end = clock();
        cout << "�६� ����� 䠩�� � �ᨭ�஭��� ०���: " << (double)(end - start) / CLOCKS_PER_SEC << " ᥪ㭤" << endl;
        cout<<"����� ���᫨⥫쭮� ��楤���"<<endl;
        start = clock();
        for (int j = 0; j < 1000; j++)
          RandNum(num);
        end = clock();
        cout<<"�����襭�� ���᫨⥫쭮� ��楤���"<<endl;
        cout << "�६� ���᫥���: " << (double)(end - start) / CLOCKS_PER_SEC << " ᥪ㭤" << endl;
    }
    return 0;
}

/*
ࠧ��� ᨭ�஭��� � ��ᨭ�஭��� - � ��ࠬ��� overlapped (� ��ᨭ�஭���)
������� overlapped �⢥砥� �� � �⮡� �㭪�� �믮��﫠�� ��᫥ ����⢨� WaitForSigleObject,
�.�. ���� �� �ந������ ��।������� ����⢨�, �ᨭ�஭��� �㭪�� �㤥� �ந�⠨����
*/
