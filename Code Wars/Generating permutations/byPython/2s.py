# not my approach
# not accepted

def permutations(s, l=0, r=-1, d={}):
    s = list(s)
    if len(s) == 1:
        yield s[0]
        return
    if l == r:
        ans = "".join(s)
        if ans not in d:
            d[ans] = True
            yield ans
    else:
        if r == -1: 
            r = len(s) - 1
        for i in range(l, r+1):
            s[l], s[i] = s[i], s[l]
            yield from permutations(s, l+1, r)
            s[l], s[i] = s[i], s[l]
    

string = input()

l = list(permutations(string))
print(sorted(l), sep="")
