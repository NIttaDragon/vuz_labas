Extrn pplab4: Far  ;
include io.asm
.model small
.stack 100
.data
  mass db 100 dup(?)
.code
.startup
start:
      inint bx ;ввод длины массива

      push bx
      push ds

      mov dx, offset mass
      push dx

      call pplab4  ;вызов ппр

      pop bx

      mov ah,9  ;вывод массива
      lea dx,mass
      int 21h

      .exit 0
end
