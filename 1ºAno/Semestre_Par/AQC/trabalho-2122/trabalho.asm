.globl main

.data

file_name_rgb:          .string "imagem.rgb"
file_name_gray:         .string "imagem.gray"

buffer_rgb:             .space 786432
buffer_gray:            .space 262144
.align 2
buffer_filtered_conv:   .space 87040
.align 2
buffer_coutour:         .space 87040
matrix_aux:             .word 0,0,0,0,0,0,0,0,0

buffer_sobel_h:         .word   1, 0, -1, 2, 0, -2, 1, 0, -1
buffer_sobel_v:         .word   1, 2, 1, 0, 0, 0, -1, -2, -1

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
    la a1, buffer_coutour
    li a2, 87040
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
convolution: # TODO ignorar 1 elemento de todas as linhas, e o ultimo
    addi sp, sp, -20
    sw s0, 0(sp)
    sw s4, 4(sp)
    sw s8, 8(sp)
    sw s5, 12(sp)
    sw s6, 16(sp)
    sw s7, 20(sp)
    li t3, 0
    li s7, 260096

loop_convolution:
    li t0, 0
    bge t3, s7, FIM_CONV
    la s4, matrix_aux
    li s8, 9
    mv s6, a0
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
    
    addi t3, t3, 4

loop_convolution_mul:
    beqz s8, update_b

    lw s0, 0(s4)
    lw s9, 0(a1)

    mul s0, s0, s9
    add t0, t0, s0

    addi s4, s4, 4
    addi a1, a1, 4
    addi s8, s8, -1

    j loop_convolution_mul

update_b:
    sw t0, 0(a2)
    addi a2, a2, 4
    
    j loop_convolution

FIM_CONV:
    lw s0, 0(sp)
    lw s4, 4(sp)
    lw s8, 8(sp)
    lw s5, 12(sp)
    lw s6, 16(sp)
    lw s7, 20(sp)
    addi sp, sp, 20
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
    li t1, 87040
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
    li t1, 87040
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
    li t1, 87040
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
    li t1, 87040
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
    ret

main:
    jal read_rgb_image
    la a0, buffer_rgb
    la a1, buffer_gray
    li a2, 786432

    jal rgb_to_gray

    la a0, buffer_gray
    la a1, buffer_sobel_h
    la a2, buffer_filtered_conv
    jal convolution
    
    mv s0, a0
    la a0, buffer_gray
    la a1, buffer_sobel_v
    la a2, buffer_filtered_conv
    jal convolution

	mv a1, s0
    la a2, buffer_coutour
    jal contour
    
    jal write_gray_image
