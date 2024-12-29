;<Maximum element>

lxi h,data
mvi b,05h

mov a,m
inx h
dcr b

loop:	cmp m
	jnc skip
	mov a,m
skip:	inx h
	dcr b
	jnz loop

hlt

data: db 03h,02h,01h,05h,06h