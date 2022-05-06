.globl main

.data
ARRAY:	.word 2, 5, 3, 0, -1 

.text

soma_array:
	addi sp, sp, -4
	sw ra, 0(sp)
	
	beqz a1, FIM
	
	lw t1, 0(a0)
	add t0, t0, t1
	addi a0, a0, 4
	addi a1, a1, -1
	jal soma_array
	

FIM:
	lw ra, 0(sp)
	addi sp, sp, 4
	mv a0, t0
	ret
	
main:
	la a0, ARRAY
	li a1, 5
	jal soma_array