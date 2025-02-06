Extrn podprog: Far  ; Указание внешнего имени дальнего типа (Другая программа)
include io.asm
.model small
.stack 100
.data
  array db 100 dup(?) ; Массив символов
  len dw ?  ; длина массива
.code
.startup
start:
      InInt len ; Ввод длины строки
      mov cx, len

      mov si, 0 ; Обнуление счетчика si, отвечающего за индекс элемента строки

starting:
      mov ah,01h  ; ввод символов в начальный массив
      int 21h
      mov array[si],al  ; Запись введенного символа в массив
      inc si
      loop starting ; цикл

      push len  ; Перемещение операнда bx в стек, значение регистра уменьшено на 4, адрес возврата записан в bp

      mov dx, offset array  ; адрес начала строки
      push dx ; отправляем значение с стек

      call podprog  ; Вызов ппр

      mov ah, 9 ; Вывод конечной строки
      lea dx, [bx]
      int 21h

      .exit 0
end
