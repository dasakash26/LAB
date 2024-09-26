.model small
.stack 100h
.data
.code
  main proc
  mov ax,@data
  mov ds,ax
  
  mov ax,0000h
  mov bx,0000h
  mov si,0040h
  mov bl,[si]
  mov si,0050h
  mov al,[si]
  mov si,0060h
  sub al,bl
  das
  jnc l1
  mov bl,al
  mov al,99h
  sub al,bl
  add al,01h
  daa
  l1:
    mov [si],al
    inc si
    mov [si],ah

  int 03h
  mov ah,4ch
  int 21h
  main endp
end main
