num(zero).
num(s(X)) :- num(X).

soma(z, X, X).
soma(s(X), Y, s(Z)) :- soma(X, Y, Z).

mult(zero, X, zero) :- num(X).
mult(s(A), B, Z) :- mult(A, B, Y), soma(Y, B, Z).

sub(X, zero, X).
sub(A, B, C) :- soma(C, B, A).

% 1.a)
fact(zero, s(z)).
fact(s(A), B) :- fact(A, B1), mult(s(A), B1, B).

% 1.b)
fact(s(A), B) :- fact(A, B).

fact(zero, F, F).
fact(s(A), FI, FO) :- lt(s(A), FI, FX), fact(A, FX, FO).

divisivel(zero, _).
divisivel(A, B) :- sub(A, B, A1), divisivel(A1, B).

% 2)
pares(_, []).
pares([_, B|L1], [B|L2]) :- pares(L1, L2).

% 3)
% 3.a)
avalia([], _, _).
% avalia([A|P], X, Y) :- avalia().