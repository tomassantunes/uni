# Frequência 3 2018

### 1.
#### a)

```ocaml
let rec append x y =
    match x with
    | [] -> y
    | h :: [] -> h :: y
    | h :: rest -> h :: append rest y
```

ou

```ocaml
let rec append = function [] -> (function lst -> lst)
    | x::rest -> function lst -> x::append rest lst
```


#### b)

```ocaml
let rec membro = function [] -> (function lst -> false)
    | x::rest -> function e -> if e = x then true else membro rest e
```


#### c)

```ocaml
let rec conta = function x -> function
    [] -> 0
    | x :: [] -> 1
    | h :: rest -> if x=h then 1 + conta x rest else conta x rest
```

ou

```ocaml
let rec conta = function e -> function [] -> 0
    | x::rest -> if e=x then 1 + conta e rest else conta e rest
```


#### d)

```ocaml
let rec remove = function x -> function
    [] -> []
    | h :: [] -> if x=h then [] else h::[]
    | h :: rest -> if x=h then remove x rest else h :: remove x rest
```

ou

```ocaml
let rec remove = function x -> function [] -> []
    | h::rest -> if x=h then remove x rest else h :: remove x rest
```


#### e)

```ocaml
let rec contagem = function [] -> []
    | x::rest -> (x, 1 + conta x rest) :: contagem(remove x rest)
```


### 2.

```ocaml
type numeral =
    | Z
    | S of numeral
```


#### a)

Temos de representar o número 3 com S(S (S Z)) em vez de S S S Z, pois este comporta-se como o nome de uma função.


#### b)

```ocaml
let rec valor = function Z -> 0
    | S x -> 1 + valor x
```


#### c)

```ocaml
let rec numeral = function 0 -> Z
    | x -> S (numeral (x-1))
```


#### d)

```ocaml
let soma = function x -> function y -> numeral ((valor x) + (valor y))
```