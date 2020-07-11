n, k = map(int, input().split())
a = []
b = []
both = []
for _ in range(n):
    x, y, z = map(int, input().split())
    if y == 1 and z == 1:
        both.append(x)
    elif y == 1:
        a.append(x)
    elif z == 1:
        b.append(x)
a.sort()
b.sort()
for i in range(min(len(a), len(b))):
    both.append(a[i]+b[i])
both.sort()
if len(both) < k:
    print(-1)
else:
    print(sum(both[:k]))
