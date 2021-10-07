# a) 2*t0 + 1

slli t1, t0, 1
addi t1, t1, 1

# b) 9*t0 + 5

slli t1, t0, 3
add t1, t1, t0
addi t1, t1, 5

# c) t0 + (-1)

addi t1, t0, -1

# d) 2*t0 + 3*(t0-t1)

sub t3, t0, t1
slli t2, t3, 1 # vezes 2
add t2, t2, t3 # vezes 3