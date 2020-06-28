r, g, b = map(int, input().split())
S = [r % 3, g % 3, b % 3]
ans = (r//3+g//3+b//3)+min(S)
if min(r, g, b) > 0:
    if S.count(2) == 2:
        ans += 1
print(ans)
