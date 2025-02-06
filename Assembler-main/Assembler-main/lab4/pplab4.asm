include io.asm
.model small
.stack 100
.data
  x db ?
.code
public pplab4
pplab4 proc far
      push bp ;пролог ппр
      mov bp, sp
      push ds
      push bx

      mov si,0
      mov cx,bx
z1:
      inch x  ;ввод символа
      mov al,x

      mov ds:[si],al  ;запись в массив символа с клавиатуры
      inc si
      mov al,'%'
      mov ds:[si],al  ;запись в массив %
      inc si

      loop z1

      mov al,'$'
      mov ds:[si],al

      newline
      pop bx
      pop ds  ;эпилог ппр
      pop bp
      ret  ;возврат в опр
pplab4 endp

end
