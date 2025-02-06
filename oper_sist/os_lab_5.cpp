//  g++ os_lab_5.cpp -lcomdlg32
//  a.exe

#include <Windows.h>
#include <string>
#include <iostream>
#include <commdlg.h> // § £®«®¢®ç­ë© ä ©« ¤«ï à ¡®âë á ¤¨ «®£®¢ë¬¨ ®ª­ ¬¨
#include <tchar.h> // § £®«®¢®ç­ë© ä ©« ¤«ï à ¡®âë á á¨¬¢®« ¬¨ Unicode
#include <stdio.h> // § £®«®¢®ç­ë© ä ©« ¤«ï à ¡®âë á ä ©« ¬¨

using namespace std;

void GetFileInfo(const TCHAR* filename) // ”ã­ªæ¨ï ¤«ï ¯®«ãç¥­¨ï ¨­ä®à¬ æ¨¨ ® ä ©«¥
{
    // ®«ãç ¥¬  âà¨¡ãâë ä ©« 
    DWORD fileAttributes = GetFileAttributes(filename);

    // à®¢¥àï¥¬, áãé¥áâ¢ã¥â «¨ ä ©«
    if (fileAttributes == INVALID_FILE_ATTRIBUTES) {
        cout << "Žè¨¡ª : ” ©« ­¥ ­ ©¤¥­." << endl;
        return;
    }

    // ®«ãç ¥¬ ¢à¥¬ï á®§¤ ­¨ï, ¯®á«¥¤­¥£® ¤®áâã¯  ¨ ¬®¤¨ä¨ª æ¨¨
    FILETIME creationTime, lastAccessTime, lastWriteTime;
    GetFileTime(CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr),
        &creationTime, // ¢à¥¬ï á®§¤ ­¨ï
        &lastAccessTime, //  à¥¬ï ¯®á«¥¤­¥£® ¤®áâã¯ 
        &lastWriteTime); //¢à¥¬ï ¯®á«¥¤­¥£® ¨§¬¥­¥­¨ï

    // à¥®¡à §ã¥¬ FILETIME ¢ SYSTEMTIME (áâàãªâãà  ¤«ï ã¤®¡­®£® ¯à¥¤áâ ¢«¥­¨ï ¤ âë ¨ ¢à¥¬¥­¨)
    SYSTEMTIME creationSysTime, lastAccessSysTime, lastWriteSysTime;
    FileTimeToSystemTime(&creationTime, &creationSysTime);
    FileTimeToSystemTime(&lastAccessTime, &lastAccessSysTime);
    FileTimeToSystemTime(&lastWriteTime, &lastWriteSysTime);

    // ®«ãç ¥¬ à §¬¥à ä ©« 
    LARGE_INTEGER fileSize;
    GetFileSizeEx(CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr), &fileSize);

    // ‚ë¢®¤¨¬ ¨­ä®à¬ æ¨î ® ä ©«¥
    cout << "ˆ¬ï ä ©« : " << filename << endl;
    cout << " §¬¥à ä ©« : " << fileSize.QuadPart << " ¡ ©â" << endl;
    cout << "‚à¥¬ï á®§¤ ­¨ï: " << creationSysTime.wDay << "." << creationSysTime.wMonth << "." << creationSysTime.wYear << " "
        << creationSysTime.wHour << ":" << creationSysTime.wMinute << ":" << creationSysTime.wSecond << endl;
    cout << "‚à¥¬ï ¯®á«¥¤­¥£® ¤®áâã¯ : " << lastAccessSysTime.wDay << "." << lastAccessSysTime.wMonth << "." << lastAccessSysTime.wYear << " "
        << lastAccessSysTime.wHour << ":" << lastAccessSysTime.wMinute << ":" << lastAccessSysTime.wSecond << endl;
    cout << "‚à¥¬ï ¯®á«¥¤­¥£® ¨§¬¥­¥­¨ï: " << lastWriteSysTime.wDay << "." << lastWriteSysTime.wMonth << "." << lastWriteSysTime.wYear << " "
        << lastWriteSysTime.wHour << ":" << lastWriteSysTime.wMinute << ":" << lastWriteSysTime.wSecond << endl;

    // ‚ë¢®¤¨¬  âà¨¡ãâë ä ©« 
    cout << "€âà¨¡ãâë ä ©« :" << endl;
    if (fileAttributes & FILE_ATTRIBUTE_READONLY)
      cout << "  ’®«ìª® ¤«ï çâ¥­¨ï" << endl;
    if (fileAttributes & FILE_ATTRIBUTE_HIDDEN)
      cout << "  ‘ªàëâë©" << endl;
    if (fileAttributes & FILE_ATTRIBUTE_SYSTEM)
      cout << "  ‘¨áâ¥¬­ë©" << endl;
    if (fileAttributes & FILE_ATTRIBUTE_ARCHIVE)
      cout << "  €àå¨¢­ë©" << endl;
}

// ”ã­ªæ¨ï ¤«ï ¨§¬¥­¥­¨ï ¬¥âª¨ â®¬ 
void ChangeVolumeLabel(const TCHAR* drive, const TCHAR* newLabel) {
    if (!SetVolumeLabel(drive, newLabel))
        cout << "Žè¨¡ª : ¥ ã¤ «®áì ¨§¬¥­¨âì ¬¥âªã â®¬ ." << endl;
    else
        cout << "Œ¥âª  â®¬  ãá¯¥è­® ¨§¬¥­¥­ ." << endl;
}

int main() {
    // ®«ãç ¥¬ ¨­ä®à¬ æ¨î ® ä ©«®¢®© á¨áâ¥¬¥
    TCHAR volumeName[MAX_PATH]; // ¡ãä¥à ¤«ï åà ­¥­¨ï ¨¬¥­¨ â®¬ 
    TCHAR SysNameBuffer[MAX_PATH]; // ¡ãä¥à ¤«ï åà ­¥­¨ï ¨­ä®à¬ æ¨¨ ® ä ©«®¢®© á¨áâ¥¬¥
    DWORD VSNumber; // ­®¬¥à ¢¥àá¨¨ ä ©«®¢®© á¨áâ¥¬ë
    DWORD MCLength; // ¬ ªá¨¬ «ì­ ï ¤«¨­  ¬¥âª¨ â®¬ 
    DWORD FileSF; //ä« £¨ ä ©«®¢®© á¨áâ¥¬ë

    GetVolumeInformation(TEXT("C:\\"), volumeName, sizeof(volumeName), &VSNumber, &MCLength, &FileSF, SysNameBuffer, sizeof(SysNameBuffer));

    // ‚ë¢®¤¨¬ ¨­ä®à¬ æ¨î ® ä ©«®¢®© á¨áâ¥¬¥
    cout << "ˆ¬ï â®¬ : " << volumeName << endl;
    cout << "ˆ­ä®à¬ æ¨ï ® ä ©«®¢®© á¨áâ¥¬¥: "<<SysNameBuffer << endl;
    cout << VSNumber << endl;

    // Žâ®¡à ¦ ¥¬ á¯¨á®ª ¤¨áª®¢ëå ãáâà®©áâ¢
    cout << "„®áâã¯­ë¥ ¤¨áª®¢ë¥ ãáâà®©áâ¢ :" << endl;
    char driveLet = 'A';
    string driveFL; // ¯ãâì ª ä«¥èª¥
    int fl = 0;
    while (driveLet <= 'Z')
    {
        string drivePath = string(1, driveLet) + ":\\"; // ä®à¬¨àã¥¬ ¯ãâì ª ¤¨áªã
        DWORD driveType = GetDriveTypeA(drivePath.c_str()); // ¯®«ãç ¥¬ â¨¯ ¤¨áª 
        cout << drivePath << " - "<< driveType << endl;
        if(driveType == 2) // § ¯®¬¨­ ¥¬ ¯ãâì ª ä«¥èª¥
        {
          driveFL = drivePath;
          fl = 1;
        }
        driveLet++;
    }

    if(fl==1) // ¨§¬¥­¥­¨¥ ¬¥âª¨ â®¬  ¤«ï ¤¨áª¥âë
    {
      cout << "‚¢¥¤¨â¥ ­®¢ãî ¬¥âªã â®¬  ¤«ï ¤¨áª¥âë: ";
      string newLabel;
      cin >> newLabel;
      ChangeVolumeLabel(driveFL.c_str(), newLabel.c_str());
    }

    // á®§¤ ­¨¥ ¤¨ «®£®¢®£® ®ª­  ¤«ï ¢ë¡®à  ä ©« 
    OPENFILENAME ofn;
    TCHAR szFileName[MAX_PATH] = _T(""); // ¯ãâì ª ä ©«ã
    ZeroMemory(&ofn, sizeof(ofn)); // ®ç¨áâª  áâàãªâãàë ofn
    ofn.lStructSize = sizeof(ofn); // ãª §ë¢ ¥¬ à §¬¥à áâàãªâãàë
    ofn.hwndOwner = NULL; // ãª §ë¢ ¥¬, çâ® ¤¨ «®£®¢®¥ ®ª­® ®â¤¥«ì­®¥
    ofn.lpstrFilter = _T("All Files (*.*)\0*.*\0"); // ä¨«ìâà æ¨ï ¯® à áè¨à¥­¨î ä ©«®¢
    ofn.lpstrFile = szFileName; // ãª §ë¢ ¥¬ £¤¥ åà ­¨âì ¯ãâì ª ä ©«ã
    ofn.nMaxFile = MAX_PATH; // ¬ ªá¨¬ «ì­ ï ¤«¨­  ¤«ï åà ­¥­¨ï ¯ãâ¨ ª ä ©«ã
    // “áâ ­ ¢«¨¢ ¥¬ ä« £¨ ¤¨ «®£®¢®£® ®ª­ , çâ®¡ë ®­® ¨á¯®«ì§®¢ «® áâ¨«ì ¯à®¢®¤­¨ª  ¨ âà¥¡®¢ «® ¢ë¡¨à âì áãé¥áâ¢ãîé¨¥ ä ©«ë
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

    if (GetOpenFileName(&ofn)) // ®â®¡à ¦ ¥¬ ¤¨ «®£®¢®¥ ®ª­® ¤«ï ¢ë¡®à  ä ©« 
    {
        cout << "‚ë¡à ­­ë© ä ©«: " << szFileName << endl;
        GetFileInfo(szFileName); // ¯®«ãç ¥¬ ¨­ä®à¬ æ¨î ® ¢ë¡à ­­®¬ ä ©«¥
        // ¯®«ãç ¥¬  âà¨¡ãâë ä ©« 
        DWORD dwAttributes = GetFileAttributes(szFileName);
        DWORD fileAttributes = GetFileAttributes(szFileName);

        if (dwAttributes != INVALID_FILE_ATTRIBUTES)
        {
            SetFileAttributes(szFileName, dwAttributes | FILE_ATTRIBUTE_READONLY);
            cout << "” ©« ®âªàëâ â®«ìª® ¤«ï çâ¥­¨ï" << endl;
            GetFileInfo(szFileName);
        }
        else
            cout << "Žè¨¡ª  ¯®«ãç¥­¨ï  âà¨¡ãâ®¢ ä ©« " << endl;
    }
    else  // ä ©« ­¥ ¢ë¡à ­
        cout << "” ©« ­¥ ¢ë¡à ­" << endl;

    return 0;
}
