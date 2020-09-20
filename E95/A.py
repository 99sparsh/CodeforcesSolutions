from math import ceil
t = int(input())
for _ in range(t):
    x, y, k = map(int, input().split())
    p = k*y + k
    moves = ceil(p/(x-1))
    moves = moves + k
    print(moves)
