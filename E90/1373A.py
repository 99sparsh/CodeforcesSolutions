t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    if c <= a:
        print(-1, b)
    elif a*b <= c:
        print(1, -1)
    else:
        print(1, b)
