%estado inicial (posição do cavalo)
estado_inicial((1,1)).

%estado final
estado_final((8,8)).
	

%op(Estado_act,operador,Estado_seg,Custo)
op((X,Y), (N,M), (X1,Y1), 1):- member(N,[1,-1]),
                               member(M,[2,-2]),
                               X1 is X+N, Y1 is Y+M, lim(X1,Y1).
op((X,Y), (N,M), (X1,Y1), 1):- member(M,[1,-1]),
			       member(N,[2,-2]), 
			       X1 is X+N, Y1 is Y+M, lim(X1,Y1).

lim(A,B) :- A =< 8, A >= 1, B =< 8, B >= 1.
