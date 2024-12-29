;<Multiplication by shift and add>

START: lxi h, data
mov e, m ; operand 1
mvi d, 00h

mov a, e
ral
jnc pos_op1
mvi d, 0ffh ; if operand 1 is negative(msb = 1)

pos_op1: inx h
mov a, m ; operand 2
mov b, a

ani 80h
jz pos_op2
mov a, b ; if operand 2 is negative
cma
inr a
mov b, a

pos_op2: mov a, b
lxi h, 0000h
mvi c, 08h

; multiplication
loop: rar
jnc skip
dad d
skip: xchg
dad h
xchg
dcr c
jnz loop

; 2's complement the result if operand 2 is negative
xchg
lxi h, data
inx h
mov a, m
ral
jnc end
mov a, e
cma
mov e, a
mov a, d
cma
mov d, a
inx d

end: xchg
hlt

data: db 89h, 85h 