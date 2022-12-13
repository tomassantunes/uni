print_string "Hello world";;

2 + 3;; (* int add *)

2.3 +. 3.2;; (* float add *)

let x = 2;; (*int var*)

let y = 2.;; (*float var*)

let my_str = "Hello World";; (*string var*)

let var = 8 in var * var;; (*64*)

let j = 1 + 4 in j * 3;; (*15*)

let lst = [1; 2; 3; 4];;

let str_lst = ["Hello"; "World"];;

let tup = (1, 2, 3, 4);;

let increment x = x + 1;;

let increment' (x: float) : float = x +. 1.;;

let add x y = x + y;;

let add' (x: float) (y: float) : float = x +. y;;

(*recursive functions*)
let rec fib x = 
  if x = 0 then 0 else
    if x < 3 then 1 else fib (x - 1) + fib (x - 2);;

(* Exercise 1: Write a function name circle_area 
   it will take in argument 'r' (radius) and returns
   the area of the circle *)

let circle_area (r: float) : float = 
  r *. r *. 3.14;;

(* Exercise 2: Write a recursive function named power
   that takes in a power 'n' and a float 'x' and
   returns x ^ n *)

let rec power (x: float) (n: int): float =
  if n = 0 then 1. else 
    x *. power x (n - 1);;

(* Exercise 3: Write a function named gcd that computes
   the greatest commond divisor of two positive integers *)

let gcd (x: int) (y: int) : int =
  let min = if x < y then x else y
in
let rec dec m = 
  if x mod m = 0 && y mod m = 0
    then m else dec (m - 1)
in
dec min