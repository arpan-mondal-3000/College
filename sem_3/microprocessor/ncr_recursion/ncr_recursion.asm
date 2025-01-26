
;<nCr using recursion>

lxi h,data
mov b,m ; n
inx h
mov c,m ; r
mvi e,00h ; nCr

call ncr
hlt

ncr: 	mov a,b ; if n<r
	cmp c
	rc 
	cpi 01h ; if n=1
	jnz skip1
	inr e
	ret
skip1:	mov a,c ; if r=1
	cpi 01h
	jnz skip2
	mov a,b
	add e
	mov e,a
	ret
skip2: 	mov a,c ; if r=0
	adi 00h
	jnz skip3
	inr e
	ret
skip3: 	dcr b
	push b
	call ncr
	pop b
	dcr c
	push b
	call ncr
	pop b
	ret

data: db 0ah,05h
