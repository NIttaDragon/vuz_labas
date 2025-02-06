include io.asm
.model small
.stack 100
.data
  mass db 100 dup(?)
.code

get macro si,al ; макроопределение
      mov mass[si],'%'  ;запись в массив %
      inc si
      mov mass[si],al  ;запись в массив символа с клавиатуры
      inc si
endm

.startup
start:
      mov si,0 ;начальное значение массива
      InInt bx
      ;mov bx,6
      mov cx,bx

z1:
      mov ah,01h ;ввод символа
      int 21h
      mov ah,0

      get si,al ; макрокоманда

      loop z1  ;цикл

      mov mass[si], '$'  ;запись в массив конца массива
      mov si,0
      add bx,bx
      mov cx,bx
      newline
z2:
      mov dl,mass[si]
      mov ah,2
      int 21h
      inc si
      newline

      loop z2

      .exit 0
end
