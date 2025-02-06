include io.asm
.model small
.stack 100
.data
  mass db 100 dup(?)
.code
.startup
start:
      mov si,0 ;начальное значение массива
      mov bx,6
      mov cx,bx

z1:
      mov ah,01h ;ввод символа
      int 21h
      mov ah,0
      cmp al,' '
      je k1 ;=
      jne k2 ;<>
k1:
      inc si
      jmp k3
k2:
      mov mass[si],al
      inc si
      jmp k3
k3:
      loop z1

      mov mass[si], '$'  ;запись в массив конца массива
      mov si,0
      ;add bx,bx
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
