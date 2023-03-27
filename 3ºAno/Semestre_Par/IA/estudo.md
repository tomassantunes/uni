## Grupo 1
### 1.

```prolog
estado_inicial([20, 30, 40, 60, 30, 120, 30, 10, 40, 40], [], [], []).
estado_final([], _, _, _).

op(([C|T], J1, J2, J3), entra(C, j1)), (T, [C|J1], J2, J3), 1) :- veCap([T|J1], 0, 140).
op(([C|T], J1, J2, J3), entra(C, j2)), (T, J1, [C|J2], J3), 1) :- veCap([T|J2], 0, 140).
op(([C|T], J1, J2, J3), entra(C, j3)), (T, J1, J2, [C|J3]), 1) :- veCap([T|J3], 0, 140).

veCap([], A, B) :- A =< B.
veCap([C|T], A, B) :- C is A + C, veCap(T, C, B). 
```

### 2.
A melhor solução encontra-se à profundidade de 10, pois em cada nível entra um turista, e há 10 turistas. E a ramificação de cada estado é 3, porque há 3 jangadas.

### 3.
???? WTF

### 4.
O número de turistas na margem do rio é um heurística para este problema porque em cada ação só entra um turista, a heurística admissível.

```prolog
h((TM, _, _, _), V) :- length(TM, V).
```

## Grupo 2
### 1.
```prolog
estado_inicial(e([var(t1, [1, 2, 3], _), var(t2, [1, 2, 3], _), ..., var(t10, [1, 2, 3], _)], [])).
```

### 2.
```prolog
sucessor(e([V, D, _]|R, Inst), e(R, e[V, D, V1]|Inst)) :- member(V1, D).
```

### 3.
Uma jangada não pode ter um conjunto de turistas cujo total de peso não seja maior que 140.

### 4.
```prolog
verifica_restricoes(e(_, R)) :- verificaJ1(R, 0, 140), verificaJ2(R, 0, 140), verificaJ3(R, 0, 140).

verificaJ1([], P, M) :- P =< M.
verificaJ1([var(PESO, _, 1)|R], P, M) :- P1 is P + PESO, verificaJ1(R, P1, M).
verificaJ1([var(PESO, _, _)|R], P, M) :- verificaJ1(R, P, M).

verificaJ2([], P, M) :- P =< M.
verificaJ2([var(PESO, _, 2)|R], P, M) :- P1 is P + PESO, verificaJ2(R, P1, M).
verificaJ2([var(PESO, _, _)|R], P, M) :- verificaJ2(R, P, M).

verificaJ2([], P, M) :- P =< M.
verificaJ2([var(PESO, _, 3)|R], P, M) :- P1 is P + PESO, verificaJ3(R, P1, M).
verificaJ2([var(PESO, _, _)|R], P, M) :- verificaJ3(R, P, M).
```

### 5.
Com a pesquisa backtracking a solução será encontrada à profundidade 10, pois há 10 turistas.