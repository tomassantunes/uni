% T W O F U R 
two([T, W, O, F, U, R]) :- fd_domain([T, W, O, F, U, R], 0, 9), T #> 0, F #>0, fd_all_different([T, W, O, F, U, R]),
O + 10 * (W + 10 * T) + O + 10 * (W + 10 * T) #= R + 10 * (U + 10 * (O + 10 * F)).

two_labeling([T, W, O, F, U, R]) :- fd_domain([T, W, O, F, U, R], 0, 9), T #> 0, F #>0, fd_all_different([T, W, O, F, U, R]),
O + 10 * (W + 10 * T) + O + 10 * (W + 10 * T) #= R + 10 * (U + 10 * (O + 10 * F)), fd_labeling([T, W, O]).

two_columns([T, W, O, F, U, R]) :- 
    fd_domain([T, W, O, F, U, R], 0, 9), fd_domain([T1, T2, T3], 0, 1), T #> 0, F #>0, fd_all_different([T, W, O, F, U, R]),
    O + O #= T1 * 10 + R,
    T1 + W + W #= T2 * 10 + U,
    T2 + T + T #= T3 * 10 + O,
    T3 #= F.