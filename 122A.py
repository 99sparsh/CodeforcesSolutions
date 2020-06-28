n = int(input())
a = [4, 7, 44, 47, 77, 74, 444, 447, 474, 777, 774, 747, 744, 477]
if n in a:
    print("YES")
else:
    for i in a:
        if n % i == 0:
            print("YES")
            quit()
    print("NO")
