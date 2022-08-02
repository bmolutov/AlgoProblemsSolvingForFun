# simple approach

def find(u):
    if u == representative[u]:
        return u
    else: 
        return find(representative[u])


def combine(u, v):
    u = find(u)
    v = find(v)

    if u == v:
        return
    else: 
        representative[v] = u

