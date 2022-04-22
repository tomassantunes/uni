.globl main

.data
A:	.string "Hello World!"

.text
string_size:	
	li t1, 0
	
CICLO:
	lb t0, 0(a0)
	beqz t0, FIM
	addi t1, t1, 1

SALTA:	addi a0, a0, 1
	j CICLO

FIM:
	mv a0, t1
	ret
	
main:
	la a0, A
	jal ra, string_size