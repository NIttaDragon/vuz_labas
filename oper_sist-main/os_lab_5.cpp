//  g++ os_lab_5.cpp -lcomdlg32
//  a.exe

#include <Windows.h>
#include <string>
#include <iostream>
#include <commdlg.h> // заголовочный файл для работы с диалоговыми окнами
#include <tchar.h> // заголовочный файл для работы с символами Unicode
#include <stdio.h> // заголовочный файл для работы с файлами

using namespace std;

void GetFileInfo(const TCHAR* filename) // Функция для получения информации о файле
{
    // Получаем атрибуты файла
    DWORD fileAttributes = GetFileAttributes(filename);

    // Проверяем, существует ли файл
    if (fileAttributes == INVALID_FILE_ATTRIBUTES) {
        cout << "Ошибка: Файл не найден." << endl;
        return;
    }

    // Получаем время создания, последнего доступа и модификации
    FILETIME creationTime, lastAccessTime, lastWriteTime;
    GetFileTime(CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr),
        &creationTime, // время создания
        &lastAccessTime, // аремя последнего доступа
        &lastWriteTime); //время последнего изменения

    // Преобразуем FILETIME в SYSTEMTIME (структура для удобного представления даты и времени)
    SYSTEMTIME creationSysTime, lastAccessSysTime, lastWriteSysTime;
    FileTimeToSystemTime(&creationTime, &creationSysTime);
    FileTimeToSystemTime(&lastAccessTime, &lastAccessSysTime);
    FileTimeToSystemTime(&lastWriteTime, &lastWriteSysTime);

    // Получаем размер файла
    LARGE_INTEGER fileSize;
    GetFileSizeEx(CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr), &fileSize);

    // Выводим информацию о файле
    cout << "Имя файла: " << filename << endl;
    cout << "Размер файла: " << fileSize.QuadPart << " байт" << endl;
    cout << "Время создания: " << creationSysTime.wDay << "." << creationSysTime.wMonth << "." << creationSysTime.wYear << " "
        << creationSysTime.wHour << ":" << creationSysTime.wMinute << ":" << creationSysTime.wSecond << endl;
    cout << "Время последнего доступа: " << lastAccessSysTime.wDay << "." << lastAccessSysTime.wMonth << "." << lastAccessSysTime.wYear << " "
        << lastAccessSysTime.wHour << ":" << lastAccessSysTime.wMinute << ":" << lastAccessSysTime.wSecond << endl;
    cout << "Время последнего изменения: " << lastWriteSysTime.wDay << "." << lastWriteSysTime.wMonth << "." << lastWriteSysTime.wYear << " "
        << lastWriteSysTime.wHour << ":" << lastWriteSysTime.wMinute << ":" << lastWriteSysTime.wSecond << endl;

    // Выводим атрибуты файла
    cout << "Атрибуты файла:" << endl;
    if (fileAttributes & FILE_ATTRIBUTE_READONLY)
      cout << "  Только для чтения" << endl;
    if (fileAttributes & FILE_ATTRIBUTE_HIDDEN)
      cout << "  Скрытый" << endl;
    if (fileAttributes & FILE_ATTRIBUTE_SYSTEM)
      cout << "  Системный" << endl;
    if (fileAttributes & FILE_ATTRIBUTE_ARCHIVE)
      cout << "  Архивный" << endl;
}

// Функция для изменения метки тома
void ChangeVolumeLabel(const TCHAR* drive, const TCHAR* newLabel) {
    if (!SetVolumeLabel(drive, newLabel))
        cout << "Ошибка: Не удалось изменить метку тома." << endl;
    else
        cout << "Метка тома успешно изменена." << endl;
}

int main() {
    // Получаем информацию о файловой системе
    TCHAR volumeName[MAX_PATH]; // буфер для хранения имени тома
    TCHAR SysNameBuffer[MAX_PATH]; // буфер для хранения информации о файловой системе
    DWORD VSNumber; // номер версии файловой системы
    DWORD MCLength; // максимальная длина метки тома
    DWORD FileSF; //флаги файловой системы

    GetVolumeInformation(TEXT("C:\\"), volumeName, sizeof(volumeName), &VSNumber, &MCLength, &FileSF, SysNameBuffer, sizeof(SysNameBuffer));

    // Выводим информацию о файловой системе
    cout << "Имя тома: " << volumeName << endl;
    cout << "Информация о файловой системе: "<<SysNameBuffer << endl;
    cout << VSNumber << endl;

    // Отображаем список дисковых устройств
    cout << "Доступные дисковые устройства:" << endl;
    char driveLet = 'A';
    string driveFL; // путь к флешке
    int fl = 0;
    while (driveLet <= 'Z')
    {
        string drivePath = string(1, driveLet) + ":\\"; // формируем путь к диску
        DWORD driveType = GetDriveTypeA(drivePath.c_str()); // получаем тип диска
        cout << drivePath << " - "<< driveType << endl;
        if(driveType == 2) // запоминаем путь к флешке
        {
          driveFL = drivePath;
          fl = 1;
        }
        driveLet++;
    }

    if(fl==1) // изменение метки тома для дискеты
    {
      cout << "Введите новую метку тома для дискеты: ";
      string newLabel;
      cin >> newLabel;
      ChangeVolumeLabel(driveFL.c_str(), newLabel.c_str());
    }

    // создание диалогового окна для выбора файла
    OPENFILENAME ofn;
    TCHAR szFileName[MAX_PATH] = _T(""); // путь к файлу
    ZeroMemory(&ofn, sizeof(ofn)); // очистка структуры ofn
    ofn.lStructSize = sizeof(ofn); // указываем размер структуры
    ofn.hwndOwner = NULL; // указываем, что диалоговое окно отдельное
    ofn.lpstrFilter = _T("All Files (*.*)\0*.*\0"); // фильтрация по расширению файлов
    ofn.lpstrFile = szFileName; // указываем где хранить путь к файлу
    ofn.nMaxFile = MAX_PATH; // максимальная длина для хранения пути к файлу
    // Устанавливаем флаги диалогового окна, чтобы оно использовало стиль проводника и требовало выбирать существующие файлы
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

    if (GetOpenFileName(&ofn)) // отображаем диалоговое окно для выбора файла
    {
        cout << "Выбранный файл: " << szFileName << endl;
        GetFileInfo(szFileName); // получаем информацию о выбранном файле
        // получаем атрибуты файла
        DWORD dwAttributes = GetFileAttributes(szFileName);
        DWORD fileAttributes = GetFileAttributes(szFileName);

        if (dwAttributes != INVALID_FILE_ATTRIBUTES)
        {
            SetFileAttributes(szFileName, dwAttributes | FILE_ATTRIBUTE_READONLY);
            cout << "Файл открыт только для чтения" << endl;
            GetFileInfo(szFileName);
        }
        else
            cout << "Ошибка получения атрибутов файла" << endl;
    }
    else  // файл не выбран
        cout << "Файл не выбран" << endl;

    return 0;
}
