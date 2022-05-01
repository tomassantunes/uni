.globl main
.text

max:
	mv t0, a0
	mv t1, a1
	blt t0, t1, second
	j FIM

second:
	mv a0, t1
	
FIM:
	ret

main:
	li a0, 3
	li a1, 6
	jal ra, max