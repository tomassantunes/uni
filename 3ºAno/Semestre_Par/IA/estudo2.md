# Freq 2 2021

# Grupo I
## 1.
A -> 6

B -> 6

C -> 1

D -> 6

E -> 7

F -> 8

G -> 6

H -> 1

I -> 5

J -> 8

## 2.
I, U

## 3.
A melhor é a jogada é a que leva de A para D.

## 4.

PGPG

GPGP

PPGG

### a)
```prolog
estado_inicial(e([P,G,P,G], [G,P,G,P], [P,P,G,G])).
terminal(e(L1, L2, L3)) :- conta(L1, N1), conta(L2, N2), conta(L3, N3), N is N1+N2+N3, N=6.

valor(e(L1, L2, L3), 1) :- contaG(L1, N1), contaG(L2, N2), contaG(L3, N3), N is N1+N2+N3, N>3.
valor(e(L1, L2, L3), 0) :- contaG(L1, N1), contaG(L2, N2), contaG(L3, N3), N is N1+N2+N3, N=3.
valor(e(L1, L2, L3), -1) :- contaG(L1, N1), contaG(L2, N2), contaG(L3, N3), N is N1+N2+N3, N<3.

op(e(L1, L2, L3), tira(1, N, A), e(L11, L2, L3)) :- tira(L1, N, A, L11), conta(L11, L2, L3, 6).
op(e(L1, L2, L3), tira(2, N, A), e(L1, L22, L3)) :- tira(L2, N, A, L22), conta(L1, L22, L3, 6).
op(e(L1, L2, L3), tira(3, N, A), e(L1, L2, L33)) :- tira(L3, N, A, L33), conta(L1, L2, L33, 6).

conta(L, N)       % N é o número de elementos em L
contaG(L, N)      % N é o número de elementos iguais a 'G' em L
conta(A, B, C, N) % sucede se a soma dos elementos em A, B e C é inferior ou igual a 6

tira(L, N, A, S)  % retira da lista L N elementos iguais a A se forem consecutivos. N é >= 1 <= 4
```

### b)
A árvora à profundidade 1 terá 14 nós, pois na primeira jogada, o jogador pode retirar 1 galinha ou um pato da primeira linha, fazendo assim, 4 jogadas possíveis. Para a segunda também terá quatro possibilidades. Para a terceira linha terá as hipóteses, retirar 1 galinha, retirar um pato, e retirar as duas galinhas ou os dois patos. Para a profundidade 2, cada nó terá no máximo 11 nós.

# Grupo II
## 1.
