let rec append = function [] -> (function lst -> lst)
  | x::rest -> function lst -> x :: append rest lst

let rec membro = function [] -> (function lst -> false)
  | x::rest -> function e -> if e=x then true else membro rest e

let rec conta = function e -> function [] -> 0
  | h::rest -> if e = h then 1 + conta e rest else conta e rest

let rec remove = function x -> function [] -> []
  | h::rest -> if x=h then remove x rest else h :: remove x rest

let rec contagem = function [] -> []
  | x::rest -> (x, 1 + conta x rest) :: contagem (remove x rest)

type numeral = 
  | Z
  | S of numeral

let rec valor = function Z -> 0
  | S x -> 1 + valor x

let rec numeral = function 0 -> Z
  | x -> S (numeral (x-1))

let rec soma = function x -> function y -> numeral ((valor x) + (valor y))