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
	
max3:	addi sp, sp, -4
	sw ra, 0(sp)
	
	jal max
	mv a1, a2
	jal max
	
FIM:
	lw ra, 0(sp)
	addi sp, sp, 4
	ret
	
main:
	li a0, 3
	li a1, 5
	li a2, 2
	jal max3