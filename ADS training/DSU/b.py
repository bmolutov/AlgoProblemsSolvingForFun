# Optimization: Union by Size 

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

    if size[u] > size[v]:
        representative[v] = u
        size[u] += size[v]
    else: 
        representative[u] = v
        size[v] += size[u]


# def combine(u, v):
#     u = find(u)
#     v = find(v)

#     if u == v:
#         return
#     else: 
#         representative[v] = u

