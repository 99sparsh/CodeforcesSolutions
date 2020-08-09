n = int(input())
mod = 1000000007
fact = 1
for i in range(1, n+1):
    fact = ((fact % mod)*(i % mod)) % mod
k = pow(2, n-1, mod)
print(k)
ans = ((fact % mod)-(k % mod)) % mod
print(ans)
