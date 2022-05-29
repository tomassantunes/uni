.globl main

.data

file_name_rgb:              .string "imagem.rgb"
file_name_gray:             .string "imagem.gray"

buffer_rgb:                 .space 786432
buffer_gray:                .space 262144
.align 2
buffer_filtered_conv_h:     .space 262144
.align 2
buffer_filtered_conv_v:     .space 262144
.align 2
buffer_contour:             .space 262144

buffer_sobel_h:             .word   1, 0, -1, 2, 0, -2, 1, 0, -1
buffer_sobel_v:             .word   1, 2, 1, 0, 0, 0, -1, -2, -1

.text

######################################################
# Funcao: read_rgb_image
# Descricao: lê um ficheiro com uma imagem no formato RGB para um array em memória
# Argumentos:
# 	a0 - uma string com o nome do ficheiro a ler 
# 	a1 - o endereço de um buffer onde a imagem deverá ser escrita
# Retorna:
# 	a0 - file descriptor do ficheiro RGB
######################################################
read_rgb_image:
    addi sp, sp, -8
    sw s6, 0(sp)
    sw s7, 4(sp)

    li a7, 1024
    la a0, file_name_rgb
    li a1, 0
    ecall
    mv s6, a0

    li a7, 63
    mv a0, s6
    la a1, buffer_rgb
    li a2, 786432
    ecall
    mv s7, a0


    li a7, 57
    mv a0, s6
    ecall
    
    mv a0, s7

    lw s6, 0(sp)
    lw s7, 4(sp)
    addi sp, sp, 8

    ret
	
######################################################
# Funcao: write_gray_image
# Descricao: escreve uma imagem em formato GRAY num ficheiro
# Argumentos:
# 	a0 - nome de um ficheiro
# 	a1 - um buffer com a imagem
#	a2 - comprimento do buffer
# Retorna:
# 	a0 - file descriptor do ficheiro GRAY
######################################################
write_gray_image:
    addi sp, sp, -4
    sw s6, 0(sp)

    li a7, 1024
    la a0, file_name_gray
    li a1, 1
    ecall
    mv s6, a0
    
    li a7, 64
    mv a0, s6
    la a1, buffer_contour
    li a2, 262144
    ecall

    li a7, 57
    mv a0, s6
    ecall

    lw s6, 0(sp)
    addi sp, sp, 4

    ret

######################################################
# Funcao: rgb_to_gray
# Descricao: converte uma imagem a cores RGB para uma imagem em tons de
#            cinzento GRAY
# Argumentos:
# 	a0 - um buffer com a imagem RGB
# 	a1 - um buffer onde deve ser colocada a imagem em formato GRAY
#	a2 - tamanho da imagem
# Retorna:
# 	a0 - buffer com os valores GRAY da imagem RGB
######################################################
rgb_to_gray:
    li t0, 100
    li t1, 30
    li t2, 59
    li t3, 11
loop_gray:
    beqz a2, FIM

    lbu t4, 0(a0)
    lbu t5, 1(a0)
    lbu t6, 2(a0)
    addi a0, a0, 3
    addi a2, a2, -3
    
    mul t4, t4, t1

    mul t5, t5, t2

    mul t6, t6, t3
    
    add t4, t4, t5
    add t4, t4, t6
    div t4, t4, t0
    
    sb t4, 0(a1)
    addi a1, a1, 1
    
    j loop_gray

FIM:
    mv a0, a1
	ret
	
######################################################
# Funcao: convolution
# Descricao: calcula a convolução de uma imagem A com um operador Sobel (matriz
# 3 × 3) e coloca o resultado numa matriz B
# Argumentos:
# 	a0 - um buffer com a matriz A
# 	a1 - um buffer com um dos operadores Sobel
#	a2 - um buffer que vai conter a imagem filtrada B
# Retorna:
# 	a0 - buffer com o resultado da convoluçaõ da imagem
######################################################
convolution:
    addi sp, sp, -16
    sw ra, 0(sp)
    sw s7, 4(sp)
    sw s6, 8(sp)
    sw s4, 12(sp)

    li t3, 0
    li s7, 260100

    li t5, 513
    add a2, a2, t5
    li t6, 510
    li t2, 260100

loop_convolution:
    bge t3, s7, FIM_CONV
    mv s6, a0
    add s6, s6, t3
    li t4, 0

    # a b c
    # d e f
    # g h i

    lbu t0, 0(s6)       # a
    lb t1, 0(a1)
    mul t4, t0, t1

    lbu t0, 1(s6)       # b
    lb t1, 1(a1)
    mul t0, t0, t1
    add t4, t4, t0

    lbu t0, 2(s6)       # c
    lb t1, 2(a1)
    mul t0, t0, t1
    add t4, t4, t0

    lbu t0, 512(s6)     # d
    lb t1, 3(a1)
    mul t0, t0, t1
    add t4, t4, t0

    lbu t0, 513(s6)     # e
    lb t1, 4(a1)
    mul t0, t0, t1
    add t4, t4, t0

    lbu t0, 514(s6)     # f
    lb t1, 5(a1)
    mul t0, t0, t1
    add t4, t4, t0

    lbu t0, 1024(s6)    # g
    lb t1, 6(a1)
    mul t0, t0, t1
    add t4, t4, t0

    lbu t0, 1025(s6)    # h
    lb t1, 7(a1)
    mul t0, t0, t1
    add t4, t4, t0

    lbu t0, 1026(s6)    # i
    lb t1, 8(a1)
    mul t0, t0, t1
    add t4, t4, t0

    addi t3, t3, 1

update_b:
    beqz t2, FIM_CONV
    beqz t6, update_count
    blt t4, zero, abs

continue:
    sb t4, 0(a2)
    addi a2, a2, 1

    addi t2, t2, -1
    addi t6, t6, -1
    
    j loop_convolution

abs:
    sub t4, zero, t4
    j continue

update_count:
    li t6, 510
    addi a2, a2, 2
    j update_b

FIM_CONV:
    mv a0, a2

    lw ra, 0(sp)
    lw s7, 4(sp)
    lw s6, 8(sp)
    lw s4, 12(sp)
    addi sp, sp, 16

    ret
    
######################################################
# Funcao: contour
# Descricao: calcula a imagem final combinando as duas imagens convolvida
# Argumentos:
# 	a0 - buffer com a imagem Bv
#   a1 - buffer com a imagem Bh
#   a2 - um buffer que vai conter a imagem final
# Retorna:
# 	a0 - buffer com a imagem final
######################################################
contour:
    addi sp, sp, -12
    sw ra, 0(sp)
    sw s1, 4(sp)
    sw s2, 8(sp)

    li t0, 4
    li t1, 262144

loop_countour_div:
    beqz t1, loop_div_done
    
    lbu s1, 0(a0)
    div s1, s1, t0
    sb s1, 0(a0)
    addi a0, a0, 1

    lbu s2, 0(a1)
    div s2, s2, t0
    sb s2, 0(a1)
    addi a1, a1, 1

    addi t1, t1, -1
    j loop_countour_div

loop_div_done:
    li t1, 262144
    mv t2, a0
    li t5, 2

loop_countour_sum:
    beqz t1, FIM_COUNTOUR
    
    lbu t3, 0(t2)
    addi t2, t2, 1

    lbu t4, 0(a1)
    addi a1, a1, 1

    add t3, t3, t4
    div t3, t3, t5
    sb t3, 0(a0)
    addi a0, a0, 1

    addi t1, t1, -1
    j loop_countour_sum
    
FIM_COUNTOUR:
    li t1, 262144
    li t5, 255

loop_strength:
    beqz t1, FIM_C

    lbu t3, 0(a2)
    sub t3, t5, t3
    sb t3, 0(a2)
    addi a2, a2, 1
    
    addi t1, t1, -1

    j loop_strength

FIM_C:
    mv a0, a2
    lw ra, 0(sp)
    lw s1, 4(sp)
    lw s2, 8(sp)
    addi sp, sp, 12
    ret

main:
    jal read_rgb_image

    la a0, buffer_rgb
    la a1, buffer_gray
    li a2, 786432
    jal rgb_to_gray

    la a0, buffer_gray
    la a1, buffer_sobel_h
    la a2, buffer_filtered_conv_h
    jal convolution
    
    la a0, buffer_gray
    la a1, buffer_sobel_v
    la a2, buffer_filtered_conv_v
    jal convolution

	la a0, buffer_filtered_conv_v
    la a1, buffer_filtered_conv_h
    la a2, buffer_contour
    jal contour
    
    jal write_gray_image