ok([]).
ok([R|Rs]) :- ok(Rs, R, 1), ok(Rs).

ok([], _, _).
ok([Rj|Rs], Ri, I) :-
    I1 is I+1,
    ok(Rs, Ri, I1),
    Ri #\= Rj, Ri #\= Rj+I, Ri+I #\= Rj.

rainhas(N, R) :- length(R, N),
    fd_domain(R, 1, N),
    ok(R),
    fd_labeling(R).

% 1 3 2 4
% 2 4 1 3
% 4 1 3 2
% ...
queens(N, QS) :-
    length(QS, N),
    fd_domain(QS, 1, N),
    fd_all_different(QS),
    fd_labeling(QS),
    nok(QS).

nok([]).
nok([R|Rs]) :- nok(Rs, R, 1), nok(Rs).

nok([], _, _).
nok([Rj|Rs], Ri, I) :-
    I1 is I+1,
    Ri =\= Rj, Ri =\= Rj+I, Ri+I =\= Rj,
    nok(Rs, Ri, I1).
    