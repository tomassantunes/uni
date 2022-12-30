as --> [].
as --> [a], as.

seq([]) --> [].
seq([E|Es]) --> [E], seq(Es).

seqq([]) --> [].
seqq([Es|Ess]) --> seq(Es), seqq(Ess).

gets(S) :- get0(C), gets([], C, S).
gets(S, 10, S).		% 10 é o newline
gets(S, -1, S).		% -1 é o end-of-file
gets(I, C, [C|O]) :- get0(CC), gets(I, CC, O).