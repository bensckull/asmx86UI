global main
extern printf
; ===== DATA SECTION =====

section .data

a dd 5 ; a est un entier sur 32 bits 
b dd 2 ; b est un entier sur 32 bits

msg_inf db "%d inferieur ou egal %d"
msg_sup_egal db "%d superieur ou egal %d"

section .text

main:
       push ebp
       mov ebp,esp
       pushad
       
       mul eax


       ; if (a<b) ...
       mov eax, [a]
       mov ebx, [b]
       cmp eax,ebx
       jge else

then:
      mov ecx,4
      push ebx
      push eax
      push  msg_inf
      call printf
      add esp, 16
      jmp endif
else:
      
      push ebx 
      push eax
      push msg_sup_egal
      call printf
      add esp, 16

endif:  

       popad
       mov esp,ebp
       pop ebp
       xor eax,eax
       ret