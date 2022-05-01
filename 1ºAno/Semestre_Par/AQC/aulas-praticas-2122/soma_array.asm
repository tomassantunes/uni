.globl main

.data
A:	.word 1, 2, 3, 4

.text

soma_array:
	add t0, zero, zero

for:
	beqz a1, FIM
	lw t1, 0(a0)
	add t0, t0, t1
	addi a0, a0, 4
	addi a1, a1, -1
	j for
	
FIM:
	mv a0, t0
	ret

main:
	la a0, A
	li a1, 4
	jal soma_array