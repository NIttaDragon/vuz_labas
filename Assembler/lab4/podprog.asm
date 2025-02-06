include io.asm
.model small
.stack 100
.data
pparray db 200 dup(?)
.code
public podprog  ; Доступ подпрограммы для других программ
podprog proc far  ; Сегмент + 16-битное смещение
      ; пролог
      push bp ; Получение адреса возврата из стека
      mov bp, sp  ; Запись Sp в bp

      mov cx, [bp+8]  ; количество итераций
      mov bx, [bp+6]  ; адрес начала строки

      mov si, 0 ; Обнуление счетчика si, отвечающего за индекс элемента строки
      mov al, '%' ; запись в al символа %

starting:
      mov dx, [bx] ; берем символ начальной строки

      mov pparray[si], dl ; запись в конечную строку символа из начальной
      inc si
      mov pparray[si], al ; запись в конечную строку символа %
      inc si
      inc bx
      loop starting ; цикл

      mov al, '$' ; Запись символа конца строки в al

      mov pparray[si], al  ; Запись в конец строки символа конца строки

      mov bx, offset pparray ; адрес начала строки

      newline
      ; эпилог
      mov sp, bp
      pop bp
      
      ret ; возврат в опр
podprog endp
end
