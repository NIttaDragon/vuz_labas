//  g++ os_lab_5.cpp -lcomdlg32
//  a.exe

#include <Windows.h>
#include <string>
#include <iostream>
#include <commdlg.h> // ���������� 䠩� ��� ࠡ��� � ��������묨 ������
#include <tchar.h> // ���������� 䠩� ��� ࠡ��� � ᨬ������ Unicode
#include <stdio.h> // ���������� 䠩� ��� ࠡ��� � 䠩����

using namespace std;

void GetFileInfo(const TCHAR* filename) // �㭪�� ��� ����祭�� ���ଠ樨 � 䠩��
{
    // ����砥� ��ਡ��� 䠩��
    DWORD fileAttributes = GetFileAttributes(filename);

    // �஢��塞, ������� �� 䠩�
    if (fileAttributes == INVALID_FILE_ATTRIBUTES) {
        cout << "�訡��: ���� �� ������." << endl;
        return;
    }

    // ����砥� �६� ᮧ�����, ��᫥����� ����㯠 � ����䨪�樨
    FILETIME creationTime, lastAccessTime, lastWriteTime;
    GetFileTime(CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr),
        &creationTime, // �६� ᮧ�����
        &lastAccessTime, // �६� ��᫥����� ����㯠
        &lastWriteTime); //�६� ��᫥����� ���������

    // �८�ࠧ㥬 FILETIME � SYSTEMTIME (������� ��� 㤮����� �।�⠢����� ���� � �६���)
    SYSTEMTIME creationSysTime, lastAccessSysTime, lastWriteSysTime;
    FileTimeToSystemTime(&creationTime, &creationSysTime);
    FileTimeToSystemTime(&lastAccessTime, &lastAccessSysTime);
    FileTimeToSystemTime(&lastWriteTime, &lastWriteSysTime);

    // ����砥� ࠧ��� 䠩��
    LARGE_INTEGER fileSize;
    GetFileSizeEx(CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr), &fileSize);

    // �뢮��� ���ଠ�� � 䠩��
    cout << "��� 䠩��: " << filename << endl;
    cout << "������ 䠩��: " << fileSize.QuadPart << " ����" << endl;
    cout << "�६� ᮧ�����: " << creationSysTime.wDay << "." << creationSysTime.wMonth << "." << creationSysTime.wYear << " "
        << creationSysTime.wHour << ":" << creationSysTime.wMinute << ":" << creationSysTime.wSecond << endl;
    cout << "�६� ��᫥����� ����㯠: " << lastAccessSysTime.wDay << "." << lastAccessSysTime.wMonth << "." << lastAccessSysTime.wYear << " "
        << lastAccessSysTime.wHour << ":" << lastAccessSysTime.wMinute << ":" << lastAccessSysTime.wSecond << endl;
    cout << "�६� ��᫥����� ���������: " << lastWriteSysTime.wDay << "." << lastWriteSysTime.wMonth << "." << lastWriteSysTime.wYear << " "
        << lastWriteSysTime.wHour << ":" << lastWriteSysTime.wMinute << ":" << lastWriteSysTime.wSecond << endl;

    // �뢮��� ��ਡ��� 䠩��
    cout << "��ਡ��� 䠩��:" << endl;
    if (fileAttributes & FILE_ATTRIBUTE_READONLY)
      cout << "  ���쪮 ��� �⥭��" << endl;
    if (fileAttributes & FILE_ATTRIBUTE_HIDDEN)
      cout << "  ������" << endl;
    if (fileAttributes & FILE_ATTRIBUTE_SYSTEM)
      cout << "  ���⥬��" << endl;
    if (fileAttributes & FILE_ATTRIBUTE_ARCHIVE)
      cout << "  ��娢��" << endl;
}

// �㭪�� ��� ��������� ��⪨ ⮬�
void ChangeVolumeLabel(const TCHAR* drive, const TCHAR* newLabel) {
    if (!SetVolumeLabel(drive, newLabel))
        cout << "�訡��: �� 㤠���� �������� ���� ⮬�." << endl;
    else
        cout << "��⪠ ⮬� �ᯥ譮 ��������." << endl;
}

int main() {
    // ����砥� ���ଠ�� � 䠩����� ��⥬�
    TCHAR volumeName[MAX_PATH]; // ���� ��� �࠭���� ����� ⮬�
    TCHAR SysNameBuffer[MAX_PATH]; // ���� ��� �࠭���� ���ଠ樨 � 䠩����� ��⥬�
    DWORD VSNumber; // ����� ���ᨨ 䠩����� ��⥬�
    DWORD MCLength; // ���ᨬ��쭠� ����� ��⪨ ⮬�
    DWORD FileSF; //䫠�� 䠩����� ��⥬�

    GetVolumeInformation(TEXT("C:\\"), volumeName, sizeof(volumeName), &VSNumber, &MCLength, &FileSF, SysNameBuffer, sizeof(SysNameBuffer));

    // �뢮��� ���ଠ�� � 䠩����� ��⥬�
    cout << "��� ⮬�: " << volumeName << endl;
    cout << "���ଠ�� � 䠩����� ��⥬�: "<<SysNameBuffer << endl;
    cout << VSNumber << endl;

    // �⮡ࠦ��� ᯨ᮪ ��᪮��� ���ன��
    cout << "����㯭� ��᪮�� ���ன�⢠:" << endl;
    char driveLet = 'A';
    string driveFL; // ���� � 䫥誥
    int fl = 0;
    while (driveLet <= 'Z')
    {
        string drivePath = string(1, driveLet) + ":\\"; // �ନ�㥬 ���� � ����
        DWORD driveType = GetDriveTypeA(drivePath.c_str()); // ����砥� ⨯ ��᪠
        cout << drivePath << " - "<< driveType << endl;
        if(driveType == 2) // ���������� ���� � 䫥誥
        {
          driveFL = drivePath;
          fl = 1;
        }
        driveLet++;
    }

    if(fl==1) // ��������� ��⪨ ⮬� ��� ��᪥��
    {
      cout << "������ ����� ���� ⮬� ��� ��᪥��: ";
      string newLabel;
      cin >> newLabel;
      ChangeVolumeLabel(driveFL.c_str(), newLabel.c_str());
    }

    // ᮧ����� ����������� ���� ��� �롮� 䠩��
    OPENFILENAME ofn;
    TCHAR szFileName[MAX_PATH] = _T(""); // ���� � 䠩��
    ZeroMemory(&ofn, sizeof(ofn)); // ���⪠ �������� ofn
    ofn.lStructSize = sizeof(ofn); // 㪠�뢠�� ࠧ��� ��������
    ofn.hwndOwner = NULL; // 㪠�뢠��, �� ���������� ���� �⤥�쭮�
    ofn.lpstrFilter = _T("All Files (*.*)\0*.*\0"); // 䨫����� �� ���७�� 䠩���
    ofn.lpstrFile = szFileName; // 㪠�뢠�� ��� �࠭��� ���� � 䠩��
    ofn.nMaxFile = MAX_PATH; // ���ᨬ��쭠� ����� ��� �࠭���� ��� � 䠩��
    // ��⠭�������� 䫠�� ����������� ����, �⮡� ��� �ᯮ�짮���� �⨫� �஢������ � �ॡ����� �롨��� �������騥 䠩��
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

    if (GetOpenFileName(&ofn)) // �⮡ࠦ��� ���������� ���� ��� �롮� 䠩��
    {
        cout << "��࠭�� 䠩�: " << szFileName << endl;
        GetFileInfo(szFileName); // ����砥� ���ଠ�� � ��࠭��� 䠩��
        // ����砥� ��ਡ��� 䠩��
        DWORD dwAttributes = GetFileAttributes(szFileName);
        DWORD fileAttributes = GetFileAttributes(szFileName);

        if (dwAttributes != INVALID_FILE_ATTRIBUTES)
        {
            SetFileAttributes(szFileName, dwAttributes | FILE_ATTRIBUTE_READONLY);
            cout << "���� ����� ⮫쪮 ��� �⥭��" << endl;
            GetFileInfo(szFileName);
        }
        else
            cout << "�訡�� ����祭�� ��ਡ�⮢ 䠩��" << endl;
    }
    else  // 䠩� �� ��࠭
        cout << "���� �� ��࠭" << endl;

    return 0;
}
