pessoa(X) :- homem(X, _, _); mulher(X, _, _).

irmao(X, Y) :- filho(X, Z), filho(Y, Z), X \= Y.
irmaos(X, L) :- pessoa(X), findall(Y, irmao(X, Y), L1), sort(L1, L).

primoDireito(X, Y) :- filho(X, Z), filho(Y, W), irmao(Z, W).
primosDireitos(X, L) :- pessoa(X), findall(Y, primoDireito(X, Y), L1), sort(L1, L).

primoSegundo(X, Y) :- primoDireito(X, Z), filho(Y, Z).
primosSegundos(X, L) :- pessoa(X), findall(Y, primoDireito(X, Y), L1), sort(L1, L).

primoTerceiro(X, Y) :- filho(X, Z), primoDireito(Z, Y).
primosTerceiros(X, L) :- pessoa(X), findall(Y, primoTerceiro(X, Y), L1), sort(L1, L).

primos(X, L) :- pessoa(X), primosDireitos(X, L1), 
            primosSegundos(X, L2),
            primosTerceiros(X, L3),
            append(L1, L2, L4), append(L4, L3, L5), sort(L5, L). 