

;<division by shift and subtract. Works only if MSB of divisor is zero>
lxi h,4567h ;dividend
mvi b,99h ;divisor
lxi d,0000h; initialize quotient
mvi c,10h ; to shift 16 times
nxtbit: dad h
        ral ; shift left from H to cy then bring to A
	jc skip
        cmp b
        jc nosub; subtract only if a>b
skip:   sub b
        inx d
nosub: dcr c
       jz end
       xchg
       dad h
       xchg ; shift quotient left 1 bit
       jmp nxtbit
end: HLT
