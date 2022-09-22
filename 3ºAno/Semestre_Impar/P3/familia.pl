homem(joao).
homem(rui).
homem(manuel).
homem(ricardo).

mulher(maria).
mulher(ana).
mulher(rita).
mulher(silvia).

progenitor(joao, maria, alex).
progenitor(joao, rui, bernardo).
progenitor(manuel, joao, joaquim).
progenitor(ricardo, manuel, catarina).
progenitor(ana, rui, amilcal).
progenitor(rita, joao, joana).
progenitor(rita, silvia, laura).

% X -> Pai, Y -> Mae, Z -> FIlho

pai(X, Y) :- homem(X), progenitor(X, Y).
mae(X, Y) :- mulher(X), progenitor(X, Y).