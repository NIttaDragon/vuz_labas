#include <Windows.h>
#include <iostream>
#include <time.h>
#include <string>
#include <random>

using namespace std;

void RandNum(int kol) // Функция для вычисления случайных данных
{
  int sum;
  for (int i = 0; i < kol; ++i)
    sum += rand();
}

void SyncOpr(const string& filename, size_t bufferSize, int num) // Функция для синхронной записи в файл
{
    HANDLE fileHandle = CreateFileA(filename.c_str(), // Имя создаваемого или открываемого файла или устройства
                                    GENERIC_WRITE, // Запрошенный доступ к файлу или устройству
                                    FILE_SHARE_READ, // Запрошенный режим общего доступа к файлу или устройству
                                    nullptr, // Указатель на структуру безопасности
                                    CREATE_ALWAYS, // Действие, выполняемое с файлом или устройством
                                    FILE_ATTRIBUTE_NORMAL, // Атрибуты и флаги файла или устройства
                                    nullptr); // Допустимый дескриптор файла шаблона
    cout<<"Открытие файла в синхронном режиме"<<endl;
    if (fileHandle == INVALID_HANDLE_VALUE) {
        cout << "Невозможно открыть файл" << endl;
        return;
    }
    char* buffer = new char[bufferSize]; // Создание буфера
    cout<<"Заполнение файла случайными значениями"<<endl;
    for (int i = 0; i < bufferSize; ++i)
        buffer[i] = rand();

    // Запись в файл
    DWORD bytesWritten;
    for (int i = 0; i < num; ++i){
        if (!WriteFile(fileHandle, buffer, bufferSize, &bytesWritten, nullptr)) {
            cout << "Ошибка записи в файл" << endl;
            break;
        }
        // cout << "Записано " << bytesWritten << " байт" << endl;
      }
    // Закрытие файла
    CloseHandle(fileHandle);
    delete[] buffer;
}


void AsyncOpr(const string& filename, size_t bufferSize, int num) // Функция для асинхронной записи в файл
{
    HANDLE fileHandle = CreateFileA(filename.c_str(), // Имя создаваемого или открываемого файла или устройства
                                    GENERIC_WRITE, // Запрошенный доступ к файлу или устройству
                                    FILE_SHARE_READ, // Запрошенный режим общего доступа к файлу или устройству
                                    nullptr, // Указатель на структуру безопасности
                                    CREATE_ALWAYS, // Действие, выполняемое с файлом или устройством
                                    FILE_ATTRIBUTE_NORMAL, // Атрибуты и флаги файла или устройства
                                    nullptr); // Допустимый дескриптор файла шаблона
    cout<<"Открытие файла в асинхронном режиме"<<endl;
    if (fileHandle == INVALID_HANDLE_VALUE) {
        cout << "Невозможно открыть файл" << endl;
        return;
    }

    char* buffer = new char[bufferSize]; // Создание буфера
    cout<<"Заполнение файла случайными значениями"<<endl;
    for (int i = 0; i < bufferSize; ++i)
        buffer[i] = rand();

    // Создание объекта для асинхронной записи
    OVERLAPPED overlapped;
    ZeroMemory(&overlapped, sizeof(overlapped));

    // Асинхронная запись в файл
    DWORD bytesWritten;
    for (int i = 0; i < num; ++i) {
        if (!WriteFile(fileHandle, buffer, bufferSize, &bytesWritten, &overlapped)) {
            if (GetLastError() == ERROR_IO_PENDING) {
                if (WaitForSingleObject(overlapped.hEvent, INFINITE) != WAIT_OBJECT_0)
                    cout << "Время ожидания ассинхронной записи вышло" << endl;
                GetOverlappedResult(fileHandle, &overlapped, &bytesWritten, FALSE); // Получение количества записанных байт
                cout << "В асинхронном режиме записано " << bytesWritten << " байт" << endl;
            } else
                cout << "Ошибка записи данных в асинхронном режиме" << endl;
        }
    }

    // Закрытие файла
    CloseHandle(fileHandle);
    delete[] buffer;
}

int main() {
    string filename = "E:\\test.txt"; // Файл на дискете
    int buffS[] = { 512, 1024, 2048, 4096 }; // Размеры буфера
    int num = 10000; // Количество итераций для вычислительной процедуры

    for (int i=0; i<4; i++){
        cout << "\nРазмер буфера: " << buffS[i] << " байт" << endl;
        clock_t start, end;
        cout<<"Запуск синхронного режима"<<endl; // Синхронная запись
        start = clock();
        SyncOpr(filename, buffS[i], buffS[i] * 1024 / buffS[i]); // Запись 1000 Кб
        end = clock();
        cout << "Время записи файла синхронном режиме: " << (double)(end - start) / CLOCKS_PER_SEC << " секунд" << endl;

        cout<<"Запуск вычислительной процедуры"<<endl;
        start = clock();
        for (int j = 0; j < 1000; j++)
          RandNum(num);
        end = clock();
        cout<<"Завершение вычислительной процедуры"<<endl;
        cout << "Время вычислений: " << (double)(end - start) / CLOCKS_PER_SEC << " секунд" << endl;

        if (DeleteFileA(filename.c_str()))
            cout << "Файл удален" << endl;
        else
            cout << "Не удалось удалить файл" << endl;

        cout<<"Запуск асинхронного режима"<<endl; // Асинхронная запись
        start = clock();
        AsyncOpr(filename, buffS[i], buffS[i] * 1024 / buffS[i]); // Запись 1000 Кб
        end = clock();
        cout << "Время записи файла в асинхронном режиме: " << (double)(end - start) / CLOCKS_PER_SEC << " секунд" << endl;
        cout<<"Запуск вычислительной процедуры"<<endl;
        start = clock();
        for (int j = 0; j < 1000; j++)
          RandNum(num);
        end = clock();
        cout<<"Завершение вычислительной процедуры"<<endl;
        cout << "Время вычислений: " << (double)(end - start) / CLOCKS_PER_SEC << " секунд" << endl;
    }
    return 0;
}

/*
разница синхронной и ассинхронной - в параметре overlapped (в ассинхронном)
структура overlapped отвечает за то чтобы функция выполнялась после действия WaitForSigleObject,
т.е. пока не произойдет определенное действие, асинхронная функция будет проистаивать
*/
