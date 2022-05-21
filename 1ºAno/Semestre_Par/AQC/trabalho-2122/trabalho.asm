.globl main

.data

file_name_rgb:          .string "imagem.rgb"
file_name_gray:         .string "imagem.gray"

buffer_rgb:             .space 786432
buffer_gray:            .space 262144
.align 2
buffer_filtered_conv_h:   .space 262144
.align 2
buffer_filtered_conv_v:   .space 262144
.align 2
buffer_contour:         .space 262144
matrix_aux:             .word 0,0,0,0,0,0,0,0,0

buffer_sobel_h:         .word   1, 0, -1, 2, 0, -2, 1, 0, -1
buffer_sobel_v:         .word   1, 2, 1, 0, 0, 0, -1, -2, -1

.text

######################################################
# Funcao: max
# Descricao: devolve o maior de dois números
# Argumentos:
# 	a0 - um inteiro positivo ou negativo
# 	a1 - um inteiro positivo ou negativo
# Retorna:
# 	a0 - o maior de dois números
######################################################
max:
	mv t0, a0
	mv t1, a1
	blt t0, t1, second
	j FIMMAX

second:
	mv a0, t1
	
FIMMAX:
	ret

######################################################
# Funcao: abs
# Descricao: devolve o absoluto de um número
# Argumentos:
# 	a0 - um inteiro positivo ou negativo
# Retorna:
# 	a0 - o absoluto de um número
######################################################
abs:
	addi sp, sp, -4
	sw ra, 0(sp)
	sub a1, zero, a0
	jal max
		
FIMABS:
	lw ra, 0(sp)
	addi sp, sp, 4
	ret

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
    mv a0, t5
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
    addi sp, sp, -36
    sw s0, 0(sp)
    sw s4, 4(sp)
    sw s8, 8(sp)
    sw s5, 12(sp)
    sw s6, 16(sp)
    sw s7, 20(sp)
    sw s1, 24(sp)
    sw s9, 28(sp)
    sw s2, 32(sp)
    li t3, 0
    li s7, 260100
    mv s1, a2
    mv s2, a1

    addi s1, s1, 512
    addi s1, s1, 512
    addi s1, s1, 512
    addi s1, s1, 512
    addi s1, s1, 4
    li t1, 510
    li t2, 260100
    j loop_convolution

loop_convolution:
    li t0, 0
    bge t3, s7, FIM_CONV
    la s4, matrix_aux # endereco matriz auxiliar
    li s8, 9 # tamanho matriz auxiliar
    mv s6, a0 # endereco da matriz A
    add s6, s6, t3

    lbu s5, 0(s6)
    sw s5, 0(s4)
    addi s4, s4, 4
    lbu s5, 1(s6)
    sw s5, 0(s4)
    addi s4, s4, 4
    lbu s5, 2(s6)
    sw s5, 0(s4)
    addi s4, s4, 4

    addi s6, s6, 512
    lbu s5, 0(s6)
    sw s5, 0(s4)
    addi s4, s4, 4
    lbu s5, 1(s6)
    sw s5, 0(s4)
    addi s4, s4, 4
    lbu s5, 2(s6)
    sw s5, 0(s4)
    addi s4, s4, 4

    addi s6, s6, 512
    lbu s5, 0(s6)
    sw s5, 0(s4)
    addi s4, s4, 4
    lbu s5, 1(s6)
    sw s5, 0(s4)
    addi s4, s4, 4
    lbu s5, 2(s6)
    sw s5, 0(s4)
    addi s4, s4, 4
    
    addi t3, t3, 1

    la s4, matrix_aux

loop_convolution_mul:
    beqz s8, update_b

    lw s0, 0(s4)
    lw s9, 0(s2)

    mul s0, s0, s9
    add t0, t0, s0

    addi s4, s4, 4
    addi s2, s2, 4
    addi s8, s8, -1

    j loop_convolution_mul

update_b:
    beqz t2, FIM_CONV
    beqz t1, update_count
    sw t0, 0(s1)
    addi s1, s1, 4
    mv s2, a1

    addi t2, t2, -1
    addi t1, t1, -1
    
    j loop_convolution

update_count:
    li t1, 510
    addi s1, s1, 8
    j update_b

FIM_CONV:
    lw s0, 0(sp)
    lw s4, 4(sp)
    lw s8, 8(sp)
    lw s5, 12(sp)
    lw s6, 16(sp)
    lw s7, 20(sp)
    lw s1, 24(sp)
    lw s9, 28(sp)
    lw s2, 32(sp)
    addi sp, sp, 36
    mv a0, s1
    ret
    
######################################################
# Funcao: contour
# Descricao: calcula a imagem final combinando as duas imagens convolvida
# Argumentos:
# 	a0 - buffer com a imagem Bv
# 	a1 - buffer com a imagem Bh
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
    mv s1, a0 # buffer Bv
    mv s2, a1 # buffer Bh

loop_countour_div:
    beqz t1, loop_div_done
    
    lw a0, 0(s1)
    jal abs
    div a0, a0, t0
    sw a0, 0(s1)
    addi s1, s1, 4

    lw a0, 0(s2)
    jal abs
    div a0, a0, t0
    sw a0, 0(s2)
    addi s2, s2, 4

    addi t1, t1, -1
    j loop_countour_div

loop_div_done:
    li t1, 262144
    mv a0, s1
    mv a1, s2
    mv t2, a0
    li t5, 2
    j loop_countour_sum

loop_countour_sum:
    beqz t1, FIM_COUNTOUR
    
    lw t3, 0(t2)
    addi t2, t2, 4

    lw t4, 0(a1)
    addi a1, a1, 4

    add t3, t3, t4
    div t3, t3, t5
    sw t3, 0(a0)
    addi a0, a0, 4

    addi t1, t1, -1
    j loop_countour_sum
    
FIM_COUNTOUR:
    li t1, 262144
    li t5, 255
    mv a0, t2
    j loop_strength

loop_strength:
    beqz t1, FIM_C

    lw t3, 0(a0)
    sub t3, t5, t3
    sw t3, 0(a2)
    addi a0, a0, 4
    addi a2, a2, 4
    
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
