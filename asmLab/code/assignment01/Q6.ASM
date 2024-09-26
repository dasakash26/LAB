.model small
.stack 100h

.data

.code
  main proc
    mov ax,@data
    mov ds,ax
    mov ax,0000h
    mov cl,05h
    mov si,0030h

    l1:
      add ax,[si]
      daa
      adc ah,00h
      inc si
      loop l1

    mov si,0040h
    mov [si],al
    inc si
    mov [si],ah

    int 03h
    mov ah,4ch
    int 21h
  main endp
end main
