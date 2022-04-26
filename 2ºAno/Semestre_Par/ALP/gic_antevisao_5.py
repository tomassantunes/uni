def is_symbol(x):
    return len(x) > 0 and ' ' not in x

def is_variable(x):
    return is_symbol(x) and x[0].isupper()

def is_terminal(x):
    return is_symbol(x) and not (is_variable(x))

def is_word(x):
    return all(is_symbol(c) for c in x)

def is_rule(x):
    v, p = x
    return is_variable(v) and is_word(p)

def is_grammar(x):
    p, s = x
    return all(is_rule(c) for c in p) and is_variable(s)

def is_regular(grammar):
    return (all(is_terminal(x[1]) for x in grammar[0])) or (all(is_terminal(x[1][0]) and is_variable(x[1][1:0]) for x in grammar[0])) or (all(len(x[1])==0 for x in grammar[0])) 
