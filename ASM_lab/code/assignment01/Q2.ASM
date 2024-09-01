.model  small
.stack 100h

.data

.code
    main proc
        mov ax, @data
        mov ds, ax
    
        mov si,0030h
        mov al, [si]
        
        not al
        inc al
        
        mov si, 0040h
        mov al,[si]
        jc l1
        not al
        inc al
        l1:
            mov [si],5000h
            mov [si],al
            cmc
            mov ah,00h
            adc ah,ah
            inc si
            mov [si],ah
    main endp
end main

