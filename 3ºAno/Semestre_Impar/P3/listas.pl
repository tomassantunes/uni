membro(X, [X|_]).
membro(X, [_|Y]) :- membro(X, Y).

tamanho([], 0).
tamanho([_|Y], N) :- tamanho(Y, N1), N is N1 + 1.

concatena([], L, L).
concatena([X1|L1], L2, [X1|L3]) :- concatena(L1, L2, L3).

list_delete(X, [X], []).
list_delete(X, [X|L1], L1).
list_delete(X, [Y|L2], [Y|L1]) :- list_delete(X, L2, L1).

list_append(A, T, T) :- membro(A, T),!.
list_append(A, T, [A|T]).

list_insert(X, L, R) :- list_delete(X, R, L).

prefixo([], _).
prefixo([X|A], [X|B]) :- prefixo(A, B).

sufixo(A, A).
sufixo(A, [_|B]) :- sufixo(A, B).

sublista(S, L) :- prefixo(S, L).
sublista(S, [_|L]) :- sublista(S, L).

nrev([], []).
nrev([X|A], B) :- nrev(A, AR), concatena(AR, [X], B).