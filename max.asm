.globl main

.data
A:	.word 1, 5, -2, 4

.text
max:	
	lw t0, 0(a0)
	addi a0, a0, 4
	
CICLO:
	beqz a1, FIM
	lw t1, 0(a0)
	ble t1, t0, SALTA
	mv t0, t1

SALTA:	addi a0, a0, 4
	addi a1, a1, -1
	j CICLO

FIM:
	mv a0, t0
	ret
	
main:
	la a0, A
	li a1, 4
	jal ra, max
