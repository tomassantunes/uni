def is_universe(x):
    return isinstance(x, set) and len(x) > 0

def is_relation(x, n, u):
    if(is_universe(u) or not isinstance(x, set)):
        for t in x:
            if len(t) != n or not isinstance(t, tuple):
                return False
            for c in t:
                if c not in u:
                    return False

        return True
    return False

def is_function(x, n, u):
    if is_relation(x, n+1, u) and len(x) == len(u)**n and len(x) > 1:
        for c in x:
            for v in x:
                if c[:n] != v[:n] or c != v:
                    return False
        return True
    return False

def is_regular(x):
    if len(x) == 0:
        return True

    c = len(list(x)[0])
    for v in x:
        if len(v) != c:
            return False
    return True

def get_universe(x):
    universe = set()
    for t in x:
        for c in t:
            universe.add(c)

    return universe
