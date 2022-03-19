def permutations(s, flags = [0]*100, ans="", d={}):

    for i in range(len(s)):

        if len(ans) == len(s):
            if ans not in d:
                yield ans
                d[ans] = True
            return

        if not flags[i]:
            flags[i] = True
            ans += s[i]
            yield from permutations(s, flags, ans)
        else:
            continue

        flags[i] = False
        ans = ans[:-1]
    

string = input()

l = list(permutations(string))
print(sorted(l), sep="")
