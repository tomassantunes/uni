colors :- [vermelho, verde, azul].

restrictions :- [(a, b), (a, g), (b, c), (b, d), (b, g), (b, f), (c, d), (d, e), (d, f), (e, f), (e, g), (f, g)].

start_state(e([
    v(c(1), colors, _),
    v(c(2), colors, _),
    v(c(3), colors, _),
    v(c(4), colors, _),
    v(c(5), colors, _),
    v(c(6), colors, _),
    v(c(7), colors, _)], [])).

see_restrictions(e())
