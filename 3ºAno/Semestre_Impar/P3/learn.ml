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
dec min;;

(* lists *)

[];;

2 :: [];;
2 :: 3 :: [];;

"Hello" :: "World" :: [];;

("Anthony", 676) :: ("John", 548) :: [];;

let int_list = [1; 2; 3; 4];;

(* Ex1: Write an OCaml function that returns true
   if all elements of the list are true *)

let rec all_true (lst: bool list) : bool =
  match lst with
  | [] -> true
  | x :: [] -> if x = true then true else false
  | x :: rest -> x && all_true rest

(* Ex2: Write a function even2ways that checks if an integer
   list only contains even values and has an even number
   of elements *)

let even x = x mod 2 = 0

let rec even2ways (lst: int list) : bool = 
  match lst with
  | [] -> true
  | x :: [] -> false
  | x1 :: x2 :: rest -> even x1 && even x2 && even2ways rest

(* Ex3: Write a function that returns true if
   the list is empty, and false otherwise *)

let is_empty (lst: 'a list) : bool = 
  if lst = [] then true else false

  (* ou *)

let is_empty2 (lst: 'a list) : bool =
  match lst with
  | [] -> true
  | _ :: _ -> false

(* Ex4: Write an OCaml function named head that 
   returns the front element of the list *)

let head (lst: 'a list) : 'a =
  match lst with
  | x :: _ -> x
  | [] -> raise (Invalid_argument "head")