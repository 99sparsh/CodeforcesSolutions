n = int(input())
a = [int(d) for d in input().split()]
f = a.count(5)
z = a.count(0)
if z == 0:
    print(-1)
elif z != 0 and f < 9:
    print(0)
else:
    x = (f//9)*9
    ans = [5]*x
    ans.extend([0]*z)
    print(*ans, sep='')
