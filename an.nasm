    ; exemple pour les registres 32 bit 
    ; définition des données 
    DATA 
  Var1 DB
 0
  Var2 DW 
0
  Var3 DD
 5
  Tab1 DB[
5
] 
  Tab2 DW[
8
] 
  Tab3 DD[
2
] 
    ; début des instructions 
    CODE 
start:  
    ;exemple PUSH/POP 
  MOV AH, 
1
  MOV AL,
 1
  PUSH AX 
  MOV BX, 
35
  PUSH BX 
  POP ECX 
    ;exemple MOV 
  MOV EDX,
2 
etiquette: 
  SHL EAX,
3 
  MOV ECX,
0
  MOV Tab1[CL],EAX 
  DEC EDX 
  ECRIRE AX 
  CMP EDX,
0 
  JNE etiquette 