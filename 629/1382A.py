from math import ceil
t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    k = ceil(a/b)
    print((b*k)-a)
