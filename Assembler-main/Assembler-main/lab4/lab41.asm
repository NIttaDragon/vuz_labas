Extrn pplab4: Far  ;ссылка на ппр
include io.asm
.model small
.stack 100
.data
  mass db 50 dup(?)
  len dw ?
  x db ?
.code
.startup
start:
      inint len ;ввод длины массива
      mov cx,len

      ;push ds
      mov si,0
z1:
      inch x  ;ввод начального массива
      mov al,x
      mov mass[si],al
      inc si

      loop z1  ;цикл заполнения начального массива

      mov dx, offset mass
      push dx
      push len

      call pplab4  ;вызов ппр

      ;pop bx
      mov ax,dx
      mov ah,9  ;вывод массива
      mov dx,ax
      int 21h

      .exit 0
end
