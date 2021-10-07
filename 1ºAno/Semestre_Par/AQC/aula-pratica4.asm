# y = 3*x + 1

#add t1, t0, t0
#add t1, t1, t0
#addi t1, t1, 1

# t0 =  0x00107fff
# t1 = 0x80000000

#srli t2, t0, 4

#srli t2, t1, 4
#0x08000000
#srai t2, t0, 4
#0x000107ff
#srai t2, t1, 4
#0xf8000000
#srli t2, t0, 5 
#0x00107fff
#0000 0000 0000 0000 1000 0011 1111 1111
#0x000083ff
#srai t2, t1, 5
#0xfc000000

#sub t2, t1, t0
#010000 00101 00110 000 00111 0110011
#slli t2, t0, 29
#0000 0001 1101 0010 1001 0011 1001 0011
#0x01d29393

srli t0, t0, 8
srli t1, t1, 8
xor t2, t0, t1
sltiu t2, t2, 1

xor t2, t0, t1
srli t2, t2, 8
sltiu t2, t2, 1

addi t2, t0, -1
and t2, t0, t2
sltiu t2, t2, 1


add t0, t0, t1
sub t1, t0, t1
sub t0, t0, t1