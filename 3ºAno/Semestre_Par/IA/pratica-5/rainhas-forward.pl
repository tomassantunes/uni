% -*- Prolog -*-

estado_inicial(e([
v(c(1),[1,2,3,4,5,6,7,8],_),                         
          v(c(2),[1,2,3,4,5,6,7,8],_),
                          v(c(3),[1,2,3,4,5,6,7,8],_),
          v(c(4),[1,2,3,4,5,6,7,8],_),
          v(c(5),[1,2,3,4,5,6,7,8],_),
                          v(c(6),[1,2,3,4,5,6,7,8],_),
          v(c(7),[1,2,3,4,5,6,7,8],_),
          v(c(8),[1,2,3,4,5,6,7,8],_)], [ v(c(1),[1,2,3,4,5,6,7,8],1)])).


%Restricoes 
%c(i) <> c(j) e |i-j| <> c(i)-c(j)

ve_restricoes(e(_Nafec,Afect)):- \+ (member(v(c(I),_Di,Vi), Afect), member(v(c(J),_Dj,Vj),Afect),  I \=J,
                                                (Vi=Vj; modDif(I,J,D1), modDif(Vi,Vj,D2), D1=D2)).
%ve_restricoes(e(Nafect,[A])).

modDif(I,J,D):- I>J, D is I-J.
modDif(I,J,D):- I '=<' J, D is J-I.

%E1= e(Lni,[v(N,D,V)|Li])

  forCheck(e(Lni,[v(N,D,V)|Li]), e(Lnii,[v(N,D,V)|Li])):-  corta(V,Lni,Lnii).

  corta(_,[],[]).
  corta(V,[v(N,D,_)|Li], [v(N,D1,_)|Lii]):- delete(D,V,D1), corta(V,Li,Lii).

 

%% escreve

esc(L):- sort(L,L1), write(L1), nl, esc1(L1).
esc1([]).
esc1([v(_,_,V)|R]):- esc(8,V,1),  esc1(R).
esc(V,V,V):- !,write(r),nl.
esc(V,_N,V):- !,write('_'),nl.
esc(V,N,N):-!,write(r), M is N+1, esc(V,N,M).
esc(V,N1,N):-write('_'), M is N+1, esc(V,N1,M).
