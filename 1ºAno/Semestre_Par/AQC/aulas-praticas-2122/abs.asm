.globl main
.text

max:
	mv t0, a0
	mv t1, a1
	blt t0, t1, second
	j FIMMAX

second:
	mv a0, t1
	
FIMMAX:
	ret

abs:
	addi sp, sp, -4
	sw ra, 0(sp)
	sub a1, zero, a0
	jal max
		
FIMABS:
	lw ra, 0(sp)
	addi sp, sp, 4
	ret
	
main:
	li a0, 3
	li a1, 6
	jal abs