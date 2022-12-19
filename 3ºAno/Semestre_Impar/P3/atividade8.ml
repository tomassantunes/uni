let rec membro = function x -> function
  [] -> false
  | h::t -> if x=h then true else membro x t

let rec conta = function x -> function
  [] -> 0
  | h::t -> if x=h then 1 + conta x t else conta x t

let rec append x y =
  match x with
  | [] -> y
  | h :: [] -> h :: y
  | h :: rest -> h :: append rest y

let rec soma_lista = function
  [] -> 0
  | x :: [] -> x
  | x :: y -> x + soma_lista y

let rec remove2 = function x -> function 
  [] -> raise (Invalid_argument "remove")
  | x :: [] -> []
  | h :: y -> if x=h then y else h :: remove2 x y

