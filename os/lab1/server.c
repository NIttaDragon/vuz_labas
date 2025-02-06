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
// Включает функции для работы со временем
#include <time.h>

// Константное определение порта, на котором сервер слушает соединения
#define PORT 8080

int main() {
  // Объявление переменных для хранения адресов сервера и клиента
  int server_socket, client_socket;
  // Объявление структуры для хранения адресов сервера и клиента
  struct sockaddr_in server_address, client_address;
  // Объявление переменной для хранения размера структуры адреса клиента
  socklen_t client_address_size;
  // Объявление буфера для храненияданных, отправляемых и получаемых от клиента
  char buffer[1024];
  // Объявление переменной для хранения текущего времени
  time_t current_time;

  // Создание сокета (AF_INET - семейство адресов (IPv4), SOCK_STREAM - тип сокета (TCP), 0 - протокол по умолчанию)
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  // Проверка создания сокета
  if (server_socket == -1) {
    perror("Сокет не создан");
    exit(1);
  }

  // Заполнение структуры адреса сервера
  // Инициализация структуры адреса сервера нулями
  memset(&server_address, 0, sizeof(server_address));
  // Установка семейства адресов IPv4
  server_address.sin_family = AF_INET;
  // Установка сервера на любой доступный IP-адресс
  server_address.sin_addr.s_addr = INADDR_ANY;
  // Преобразование номера порта в сетевой порядок байтов
  server_address.sin_port = htons(PORT);

  // Привязка сокета к указанному IP-адресу
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("Сокет не привязан к адресу");
    exit(1);
  }

  // Прослушивание входящих соединений
  printf("Прослушивание соединений\n");
  if (listen(server_socket, 5) == -1) {
    perror("Ошибка прослушивания");
    exit(1);
  }

  // Установка размера структуры адреса клиента
  client_address_size = sizeof(client_address);
  // Цикл бесконечной обработки запросов клиентов
  while (1) {
    memset(buffer, '\0', sizeof(buffer));
    // Принятие входящих соединений от клиента.
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
    // Проверка соединения
    if (client_socket == -1) {
      perror("Соединение не принято");
      exit(1);
    }
    // Сообщение об успешном подключении
    printf("Клиент подключен\n");

    // Получение данных от клиента
    recv(client_socket, buffer, sizeof(buffer), 0);
    // Провека запроса
    if (strcmp(buffer, "1") == 0) { // Получение текущего времени
      // Получение текущего времени
      current_time = time(NULL);
      // Форматирование текущего времени в строку
      strftime(buffer, sizeof(buffer), "%c", localtime(&current_time));
      // Отправка времени клиенту
      send(client_socket, buffer, strlen(buffer), 0);
      // Сообщение об окончании операции
      printf("Текущее время отправлено\n");
      printf("Отключение клиента\n");
      // Закрытие сокетов
      close(client_socket);
    }
    else if (strcmp(buffer, "2") == 0) { // Отсоединение клиента и выключение сервера
      // Сообщение о завершении работы сервера
      printf("Сервер выключается\n");
      // Закрытие сокета клиента
      close(client_socket);
      // Закрытие сокета сервера
      close(server_socket);
      // Завершение программы
      return 0;
    }
    else { // Некорректный запрос
      printf("Некорректный запрос клиента\n");
    }
  }
}
