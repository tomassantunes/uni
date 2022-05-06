.globl main

.data
ARRAY:	.word 2, 5, 3, 0, -1 

.text

max:
	bge a0, a1, FIMMAX
	mv a0, a1
	
FIMMAX:	ret

max_array:
	addi sp, sp, -8
	sw ra, 4(sp)
	sw s0, 0(sp)
	
		
	lw s0, 0(a0)
	li t0, 1
	beq a1, t0, END
	
	addi a0, a0, 4
	addi a1, a1, -1
	jal max_array
	mv a1, s0
	jal max	
	j FIM
	
END:	mv a0, s0
	
FIM:
	lw ra, 4(sp)
	lw s0, 0(sp)
	addi sp, sp, 8
	ret
	
main:
	la a0, ARRAY
	li a1, 5
	jal max_array