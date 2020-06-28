x, y = map(int, input().split())
n = int(input())
m = 1000000007
if n % 6 == 1:
    print(x % m)
elif n % 6 == 2:
    print(y % m)
elif n % 6 == 3:
    print((y % m-x % m) % m)
elif n % 6 == 4:
    print((-x) % m)
elif n % 6 == 5:
    print((-y) % m)
else:
    print((x % m-y % m) % m)
