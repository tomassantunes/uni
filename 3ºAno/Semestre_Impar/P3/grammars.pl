expr(V) --> termo(V).
expr(mais(A,B)) --> termo(A), "+", termo(B).
expr(menos(A,B)) --> termo(A), "-", termo(B).

termo(V) --> fator(V).
termo(vezes(A,B)) --> fator(A), "*", fator(B).
termo(dividir(A,B)) --> fator(A), "/", fator(B).

fator(X) --> numero(X).
fator(X) --> "(", expr(X), ")".

numero(N) --> digito(D), resto(D, N).

resto(D, N) --> digito(E), { F is 10*D + E }, resto(F, N).
resto(X, X) --> [].

digito(0) --> "0".
digito(1) --> "1".
digito(2) --> "2".
digito(3) --> "3".
digito(4) --> "4".
digito(5) --> "5".
digito(6) --> "6".
digito(7) --> "7".
digito(8) --> "8".
digito(9) --> "9".