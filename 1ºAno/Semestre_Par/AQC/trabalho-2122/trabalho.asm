.globl main

.data

file_name_rgb:      .string "imagem.rgb"
file_name_gray: .string "imagem.gray"

buffer_rgb:     .space 786432
buffer_gray:    .space 786432
buffer_filtered_conv:     .space 87040
buffer_coutour: .space 87040
matrix_aux:     .space 9

buffer_sobel_h: .word   1, 0, -1, 2, 0, -2, 1, 0, -1
buffer_sobel_v: .word   1, 2, 1, 0, 0, 0, -1, -2, -1

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
    la a1, buffer_gray
    li a2, 786432
    ecall

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

    lw t4, 0(a0)
    lw t5, 4(a0)
    lw t6, 8(a0)
    addi a0, a0, 12
    addi a2, a2, -3
    
    mul t4, t4, t1
    div t4, t4, t0

    mul t5, t5, t2
    div t5, t5, t0

    mul t6, t6, t3
    div t6, t6, t0
    
    sw t4, 0(a2)
    sw t5, 4(a2)
    sw t6, 8(a2)
    addi a2, a2, 12
    
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
    lw s2, 20(a0)
    li s3, 0
    la s4, matrix_aux
    li s7, 783360
    li t0, 0

loop_convolution:
    bge s3, s7, FIM
    li s8, 9
    mv s6, a0
    addi s6, s6, s3
    
    lw s5, 0(t6)
    sw s5, 0(s4)
    addi s4, s4, 4
    lw s5, 4(s6)
    sw s5, 0(s4)
    addi s4, s4, 4
    lw s5, 8(s6)
    sw s5, 0(s4)
    addi s4, s4, 4

    addi s6, s6, 1536
    lw s5, 0(s6)
    sw s5, 0(s4)
    addi s4, s4, 4
    lw s5, 4(s6)
    sw s5, 0(s4)
    addi s4, s4, 4
    lw s5, 8(s6)
    sw s5, 0(s4)
    addi s4, s4, 4

    addi s6, s6, 1536
    lw s5, 0(s6)
    sw s5, 0(s4)
    addi s4, s4, 4
    lw s5, 4(s6)
    sw s5, 0(s4)
    addi s4, s4, 4
    lw s5, 8(s6)
    sw s5, 0(s4)
    addi s4, s4, 4
    
    addi s3, s3, 4

    addi s7, s7, -3

loop_convolution_mul:
    beqz s8, update_b

    lw s0, 0(s4)
    lw s9, 0(a1)

    mul s0, s0, s9
    add t0, t0, s0

    addi s4, s4, 4
    addi a1, a1, 4

    j loop_convolution_mul

update_b:
    sw t0, 0(a2)
    addi a2, a2, 4
    
    j loop_convolution

FIM:
    mv a0, a2
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
    li t0, 4
    li t1, 786432
loop_countour_div:
    beqz t1, loop_div_done
    
    lw t3, 0(a0)
    div t3, t3, t0
    sw t3, 0(a0)
    addi a0, a0, 4

    lw t4, 0(a1)
    div t4, t4, t0
    sw t4, 0(a1)
    addi a1, a1, 4

    addi t1, t1, -1
    j loop_countour_div

loop_div_done:
    li t1, 786432
    mv t2, a0
    j loop_countour_sum

loop_countour_sum:
    beqz t1, loop_sum_done
    
    lw t3, 0(t2)
    addi t2, t2, 4 

    lw t4, 0(a1)
    addi a1, a1, 4 

    add t3, t3, t4
    sw t3, 0(a0)
    addi a0, a0, 4

    addi t1, t1, -1
    j loop_countour_sum
    
loop_sum_done:
    li t1, 786432
    li t4, 2
    mv t2, a0
    j loop_countour_final_div

loop_countour_final_div:
    beqz t1, FIM_COUNTOUR

    lw t3, 0(t2)
    div t3, t3, t4
    sw t3, 0(t2)
    addi t2, t2, 4

    addi t1, t1, -1
    j loop_countour_final_div

FIM_COUNTOUR:
    li t1, 786432
    li t5, 255
    mv a0, t2
    j loop_strength

loop_strength:
    beqz t1, FIM

    lw t3, 0(a0)
    sub t3, t5, t3
    sw t3, 0(a2)
    addi a0, a0, 4
    addi a2, a2, 4

    j loop_strength

FIM:
    mv a0, a2
    ret
######################################################
main:
    jal read_rgb_image
    la a0, buffer_rgb
    la a1, buffer_gray
    li a2, 786432

    jal rgb_to_gray

    jal write_gray_image

    la a0, buffer_gray
    la a1, buffer_sobel_h
    la a2, buffer_filtered_conv
    jal convolution
    
    mv a1, a0
    la a0, buffer_gray
    la a1, buffer_sobel_v
    la a2, buffer_filtered_conv
    jal convolution

    la a2, buffer_coutour
    jal contour