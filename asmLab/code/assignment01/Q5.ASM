.model small
.stack 100h
.data
.code
  main proc
  mov ds,ax
  mov ax,0000h
  mov dl,00h
  mov cx,05h
  mov si,0030h
l1:
  add ax,[si]
  adc dl,00h
  inc si
  inc si
loop l1
  mov si,0050h
  mov [si],ax
  mov si,0052h
  mov [si],dl

  int 03h
  mov ah,4ch
  int 21h
  main endp
end main
