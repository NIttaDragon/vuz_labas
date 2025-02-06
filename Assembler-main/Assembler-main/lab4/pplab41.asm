include io.asm
.model small
.stack 100
.data
  ppmass db 100 dup(?)
  pplen dw ?
  ;x db ?
.code
public pplab4
pplab4 proc far
      push bp ;пролог ппр
      mov bp, sp

      push ds
      push bx
      pop pplen

      mov cx,pplen
      mov si,0
      mov bx,0

z1:
      mov al,ds:[si]
      mov ppmass[bx],al  ;запись в массив символа с клавиатуры
      inc si
      inc bx
      mov al,'%'
      mov ppmass,al  ;запись в массив %
      inc bx

      loop z1

      mov al,'$'
      mov ppmass,al

      newline
      mov dx, offset ppmass
      pop bx
      pop ds  ;эпилог ппр
      pop bp
      ret  ;возврат в опр
pplab4 endp

end
