    .model small
    .stack 100h

    .data
        num1 db 02h
        num2 db 05h

    .code
        main proc
            mov ax, @data
            mov ds, ax
            mov al,num1
            mov bl,num2
            add al,bl
            mov dl, al
            add dl,30h 
            mov ah,02h
            int 21h
            mov ah, 4ch
            int 21h
        main endp
    end main