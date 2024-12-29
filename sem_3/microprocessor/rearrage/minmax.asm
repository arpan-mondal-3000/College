
;<Min Max>

lxi h,data
mov a,m
inx h
mvi b,04h

call loop
hlt

loop:	cmp m
	jc skip
	mov a,m
skip: 	inx h
	dcr b
	jnz loop

ret
data: db 05h,03h,01h,06h,02h
