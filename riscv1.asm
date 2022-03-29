# 5
sltiu t2, t0, 1

# 6
srli t0, t0, 8
srli t1, t1, 8
sub t3, t0, t1
sltiu t2, t3, 1

# 7
add t1, zero, t0
addi t1, t1, -1
and t0, t0, t1
sltiu t2, t0, 1

# 8
add t1, t0, t1
sub t0, t1, t0
sub t1, t1, t0

# aula pratica 5
# 1
# a)
blt t1, t0, jump
jump:
	addi t0, t0, -1

# b)
blt t0, zero, jump
add t1, zero, t0
jump: 
	sub t1, zero, t0

# c)
add t1, zero, zero
addi t0, zero, 1
addi t2, zero 10

for:
	blt t2, t0, fim
	add t1, t1, t0
	addi t0, t0, 1
	bge t2, t0, for
fim:	

# d)
addi t2, zero, 1
addi t3, zero, 2

CASE1: 	
	bne t0, t2, CASE2
	addi t1, zero, 10
CASE2: 	
	bne t0, t3, DEFAULT
	addi t1, zero, 15
DEFAULT: 
	add t1, zero, zero
end:

# ou
addi t2, zero, 1
addi t3, zero 2

beq t0, t2, CASE1
beq t0, t3, CASE2
DEFAULT: 
	add t1, zero, zero
	beq zero, zero, END
CASE1: 
	addi t1, zero, 10
	beq zero, zero, END
CASE2: 
	addi t1, zero, 15
END:

# 4
jal ra, COLLATZ

COLLATZ:
	andi t0, a0, 1
	beq t0, zero, PAR
	
IMPAR:
	slli t0, a0, 1
	add a0, a0, t0
	addi a0, a0, 1
	jal zero, FIM
	
PAR:
	srai a0, a0 1
	
FIM:
	jalr zero, 0(ra)
	
# aula 6
# 1
blt a1, a0, END
add a0, zero, a1
END:

# 2
# a1 < a0 -> a1 < a2 -> a0 = a1
# a2 < a0 -> a2 < a1 -> a0 = a2
# else a0

blt a0, a1, case1

case1:
   blt a1, a2, case2
   add a0, zero, a1

case2:
   blt a2, a0, END
   add a0, zero, a2

END:


# 3
blt a1, a0, RESULTZERO

add t0, zero, a0
add a0, zero, zero
SOMA:
   add a0, a0, t0
   addi t0, t0, 1
   beq a1, t0, END
   jal zero, SOMA

RESULTZERO:
   add a0, zero, zero

END:
   
# 4
blt a1, a0, RESULTZERO

add t0, zero, a0
add a0, zero, zero
CHECK:
   andi t1, a0, 1
   beq t1, zero, SOMA
   addi t0, t0, 1
   jal zero, CHECK

SOMA:
   add a0, a0, t0
   beq a1, t0, END
   addi t0, t0, 1
   jal zero, CHECK

RESULTZERO:
   add a0, zero, zero

END:

# 5
