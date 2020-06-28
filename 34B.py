n, m = map(int, input().split())
costs = sorted([int(d) for d in input().split()])
ans = 0
i = 0
while m > 0:
    if(costs[i] >= 0):
        break
    ans = ans+costs[i]
    i = i+1
    m = m-1
print(ans*-1)
