t = int(input())
for _ in range(t):
    s = input()
    one = 0
    z = 0
    k = 0
    for i in range(len(s)):
        if s[i] == '1':
            one = one+1
        else:
            z = z+1
    k = min(one, z)
    if k % 2 == 0:
        print("NET")
    else:
        print("DA")
