.globl main

.data
file_name:	.string "imagem.rgb"
buffer:      .word

.text
######################################################
# Funcao: read_rgb_image
# Descricao: lê um ficheiro com uma imagem no formato RGB para um array em memória
# Argumentos:
# 	a0 - uma string com o nome do ficheiro a ler 
# 	a1 - o endereço de um buffer onde a imagem deverá ser escrita
# Retorna:
# 	a0 - array com os valores rgb de cada pixel
######################################################
read_rgb_image:
    li a7, 1024
    la a0, file_name
    li a1, 0
    ecall
    mv s6, a0

    li a7, 63
    mv a0, s6
    la a1, buffer
    li a2, 512
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
# 	a0 - escreve a imagem
######################################################
write_gray_image:
	

######################################################
# Funcao: rgb_to_gray
# Descricao: converte uma imagem a cores RGB para uma imagem em tons de
#            cinzento GRAY
# Argumentos:
# 	a0 - um buffer com a imagem RGB
# 	a1 - um buffer onde deve ser colocada a imagem em formato GRAY
#	a2 - tamanho da imagem
# Retorna:
# 	a0 -
######################################################
rgb_to_gray:


######################################################
# Funcao: convolution
# Descricao: calcula a convolução de uma imagem A com um operador Sobel (matriz
# 3 × 3) e coloca o resultado numa matriz B
# Argumentos:
# 	a0 - um buffer com a matriz A
# 	a1 - um buffer com um dos operadores Sobel
#	a2 - um buffer que vai conter a imagem filtrada B
# Retorna:
# 	a0 - 
######################################################
convolution:


######################################################
# Funcao: contour
# Descricao: calcula a imagem final combinando as duas imagens convolvida
# Argumentos:
# 	a0 - buffer com a imagem Bv
# 	a1 - buffer com a imagem Bh
# Retorna:
# 	a0 - 
######################################################
contour:

######################################################
main:
    jal read_rgb_image
