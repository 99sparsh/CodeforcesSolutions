t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    a = [int(i) for i in input().split()]
    s = 0
    for i in a:
        if i % 2 == 1:
            s = s+1
    if s == 0 or (n == x and s % 2 == 0) or (s == n and x % 2 == 0):
        print("No")
    else:
        print("Yes")
