
;<Finding minimum and maximum of n numers n>= 2>
lxi sp,0ff00h
lxi h, 9000h
mov e,m; E contains the number of integers n
mov a,l
add e
mov e,a
mov d,h ; now DE points to end of array

call rearrange
hlt

rearrange: mov a,m ;a=n
        rrc ;divide by 2
       ani 7fh ; make msb 0
        mov c,a ; c=floor(n/2)
        inx h
 nxt: mov b,m
      ldax d
      cmp b
      jnc noswap
      mov m,a
      mov a,b 
      stax d ; swap the numbers pointed by DE and HL
noswap: inx h
        dcx d
        dcr c
        jnz nxt
	ret
;subroutine to find minimum


;subroutine to find maximum


     





