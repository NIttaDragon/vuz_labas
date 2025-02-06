// Включает стандартный ввод/вывод
#include <stdio.h>
// Включает стандартные функции
#include <stdlib.h>
// Включает функции для работы со строками
#include <string.h>
// Включает POSIX-совместимые функции
#include <unistd.h>
// Включает функции для работы с сокетами
#include <sys/socket.h>
// Включает определения для интернет-протоколов
#include <netinet/in.h>
//Включает функции для преобразования IP-адресов
#include <arpa/inet.h>

// Константное определение порта, на котором сервер будет прослущивать соединения
#define PORT 8080
// Константное объявления IP-адреса сервера
#define SERVER_IP "127.0.0.1"

int main() {
  // Объявление переменной для хранения дескриптера сокета клиента
  int client_socket;
  //Объявление структуры для хранения адреса сервера
  struct sockaddr_in server_address;
  // Объявление буфера для хранения данных, отправляемых и получаемых от сервера
  char buffer[1024];

  // Создание сокета (AF_INET - семейство адресов (IPv4), SOCK_STREAM - тип сокета (TCP), 0 - протокол по умолчанию)
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  // Проверка создания сокета
  if (client_socket == -1) {
    perror("Сокет не создан\n");
    exit(1);
  }

  // Заполнение структуры адреса сервера
  // Инициализация структуры адреса сервера нулями
  memset(&server_address, 0, sizeof(server_address));
  // Установка семейства адресов IPv4
  server_address.sin_family = AF_INET;
  // Преобразование строку с IP-адресом в числовой формат
  server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
  // Преобразование номера порта в сетевой порядок байтов
  server_address.sin_port = htons(PORT);

  // Попытка установить соединение с сервером
  if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("Соединение не установлено\n");
    exit(1);
  }

  // Меню управления действий клиента
  // Переменная для записи выбора
  int change;
  // Меню действий
  printf("Подключение к серверу прошло успешно. Выберите действие:\n");
  printf("1. Вывести текущее время\n");
  printf("2. Выключить сервер\n");

  // Очистка буфера перед использованием
  memset(buffer, '\0', sizeof(buffer));
  // Чтение выбора пользователя
  scanf("%d", &change);
  // Анализ выбора пользователя
  switch(change) {
    case 1: // Запрос текущего времени
    {
      // Запись в буфер выбор пользователя
      strcpy(buffer, "1");
      // Отправка запроса на сервер
      send(client_socket, buffer, strlen(buffer), 0);
      // Получение ответа от сервера
      recv(client_socket, buffer, sizeof(buffer), 0);
      // Вывод времени на экран
      printf("Текущее время: %s\n", buffer);
      // Сообщение об отключении от сервера
      printf("Отключение\n");
      // Закрытие сокета клиента
      close(client_socket);
      // Завершение программы
      return 0;
    }
    case 2: // Завершение работы
    {
      // Запись в буфер выбор пользователя
      strcpy(buffer, "2");
      // Отправка запроса на сервер
      send(client_socket, buffer, strlen(buffer), 0);
      // Закрытие сокета клиента
      close(client_socket);
      // Завершение программы
      return 0;
    }
    default: //Иной выбор
    {
      printf("Неверно указан пункт меню\n"); 
      break;
    }
  }
}
