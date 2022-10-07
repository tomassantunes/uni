- Uma **constante** (um literal) pode ser:
	- Um número
	- Um átomo
		- Um átomo é expresso como uma string entre 'plicas'
		- Se não tiver caracteres estranhos (p/ex espaços) não precisa de 'plicas'
		- Não deve começar por uma maiúscula

- Um **termo composto**, um termo com
	- Uma "etiqueta", ou cabeça, que é um átomo
	- Um ou mais **subtermos**, indexados
	- Diz-se que um termo composto tem **aridade N** se tiver N subtermos

- Uma **variável**
	- Sintacticamente é como um "identificador"
	- Primeiro caracter uma **maiúscula** ou "__"

#### Predicado
```prolog
p(a, 1, 2). % -> p/3
```

```prolog
p(a, xpto). % -> p/2
```

Notação: **NOME / ARIDADE**
Ex: **morada/3** -> **morada(RUA, NUM, ANDAR)**

#### Predicados "base de dados"
```prolog
% filho(FILHO, PAI)

filho(tomas, francisco).
filho(tomas, ana).
filho(mariana, francisco).
filho(mariana, ana).
filho(francisco, antonio).
filho(francisco, francisca).
```

Entende-se **filho(A, B)** como "A é filho de B".

```prolog
homem(francisco).
homem(tomas).
homem(antonio).

mulher(ana).
mulher(mariana).
mulher(francisca).
```

#### Cláusulas com corpo não vazio
```prolog
mulher(X) :- \+ homem(X).
```
