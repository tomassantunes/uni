% -*- Prolog -*-

:- dynamic(nos/1).

nos(0).

inc:- retract(nos(N)), N1 is N+1, asserta(nos(N1)).

  
p:- estado_inicial(E0), back(E0,A),  esc(A).

back(e([],A),A).
  back(E,Sol):- sucessor(E,E1), inc, ve_restricoes(E1),
                       forCheck(E1,E2),
                          back(E2,Sol).

sucessor(e([v(N,D,V)|R],E),e(R,[v(N,D,V)|E])):- member(V,D).
