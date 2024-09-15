; CYCLE SIMULATION, like :
; for(int i = 0; i < 10 ; i++){...}

start: ; label 'start'
mov cl, 0; CL = 0
mov ch, 10; CH = 10
for: ; label 'for'
cmp ch, cl ; CH == CL ? ..
jz finish ; CH == CL : jump on finish 
inc cl ; CL++
; at here you can put instruction of circle 
jmp for ; else jump on for 
finish: ; label 'finish'  



; CYCLE SIMULATION, like :
; while (TRUE){...}
; let's agree that TRUE = 1 , FALSE = 0 and in our cycle we have a depth of 3. 

letsStart: ; label 'let`s start'
mov byte [BOOL], 1 ; TRUE = 1. Remark: variabels is working better and slowly that registers. It`s created for example.
mov byte al, 0 ; register for change state variable 'BOOL' 
mov ah , 3 ; Addithion condition: "AH = 3"
mov bh , 0 ; for condition 
while: ; label 'while'
cmp ah , bh ; AH == BH ? ..
jz end ; if AH == BH - exit from while cycle
dec ah ; AH--

cmp BOOL, al ; BOOL == AL ? .. 
jnz while: ; if not - return to label 'while'

jmp end ; else - exit from while cycle 
end: ; label 'end'
mov BOOL, 0 ; BOOL = 0 (FALSE)


