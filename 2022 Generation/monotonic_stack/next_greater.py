def find_next_greater(arr):
    n = len(arr)
    stack = []

    next_greater = [-1] * n

    for i in range(n):
        while stack and arr[stack[-1]] < arr[i]:
            top = stack.pop(-1)
            next_greater[top] = arr[i]

        stack.append(i)

    return next_greater


arr = [int(i) for i in input().split()]
print(find_next_greater(arr))

