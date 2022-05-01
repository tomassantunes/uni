.globl main

.data
A:	.word 1, 2, 3, 4

.text

max:
	addi sp, sp, -4
	sw ra, 0(sp)
	
	lw t0, 0(a0)
	blt t1, t0, second
	jal FIMMAX

second:
	mv t1, t0
	
FIMMAX:
	lw ra, 0(sp)
	addi sp, sp, 4
	ret
	
array_max:
	addi sp, sp, -4
	sw ra, 0(sp)
	
	lw t1, 0(a0)
	addi a0, a0, 4
for:
	beqz a1, FIM
	jal max
	addi a0, a0, 4
	addi a1, a1, -1
	j for
	
FIM:
	mv a0, t1
	lw ra, 0(sp)
	addi sp, sp, 4
	ret
	

main:
	la a0, A
	li a1, 4
	jal array_max
