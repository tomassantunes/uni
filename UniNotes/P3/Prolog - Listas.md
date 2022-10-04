### Métodos de listas
- Verificar se X está na lista
```prolog
list_member(X, [X|_]).
list_member(X, [_|TAIL]) :- list_member(X, TAIL).
```

- Contar o número de elementos na lista
```prolog
list_length([], 0).
list_length([_|TAIL], N) :- list_length(TAIL, N1), N is N1 + 1.
```

- Juntar duas listas
```prolog
list_concat([], L, L).
list_concat([X1|L1], L2, [X1|L3]) :- list_concat(L1, L2, L3).
```

- Apagar um elemento X de uma lista
```prolog
list_delete(X, [X], []).
list_delete(X, [X|L1], L1).
list_delete(X, [Y|L2], [Y|L1]) :- list_delete(X, L2, L1).
```

- Inserir elemento no ínicio da lista
```prolog
list_append(A, T, T) :- list_member(A, T),!.
list_append(A, T, [A|T]).
```

- Inserir elemento na lista
```prolog
list_insert(X, L, R) :- list_delete(X, R, L).
```

