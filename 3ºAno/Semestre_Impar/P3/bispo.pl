diagonal_direita_para_cima((LX, CX), LI, CI):- LI=<8, CI=<8, LX#=LI, CX#=CI,
                                               LII is LI+1, CII is CI+1, 
                                               diagonal_direita_para_cima((LX,CX), LII, CII).

diagonal_direita_para_baixo((LX, CX), LI, CI):- LI>=1, CI=<8, LX#=LI, CX#=CI,
                                                LII is LI-1, CII is CI+1,
                                                diagonal_direita_para_baixo((LX, CX), LII, CII).

diagonal_esquerda_para_cima((LX, CX), LI, CI):- LI=<8, CI>=1, LX#=LI, CX#=CI,
                                                LII is LI+1, CII is CI-1,
                                                diagonal_esquerda_para_cima((LX, CX), LII, CII).

diagonal_esquerda_para_baixo((LX, CX), LI, CI):- LI>=1, CI>=1, LX#=LI, CX#=CI,
                                                LII is LI-1, CII is CI-1,
                                                diagonal_esquerda_para_baixo((LX, CX), LII, CII).

na_bispo((LB, CB), (LX, CX)):- LDC is LB+1, CDC is CB+1, diagonal_direita_para_cima((LX, CX), LDC, CDC),
                                LDB is LB-1, CDB is CB+1, diagonal_direita_para_baixo((LX, CX),LDB, CDB),
                                LEC is LB+1, CEC is CB-1, diagonal_esquerda_para_cima((LX, CX), LEC, CEC),
                                LEB is LB-1, CEB is CB-1, diagonal_esquerda_para_baixo((LX, CX), LEB, CEB).

na_torre((LT,CT), (LX, CX)):- LX #= LT, CX #= CT.