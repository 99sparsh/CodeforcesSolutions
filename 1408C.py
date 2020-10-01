for q in range(int(input())):
    n, l = map(int, input().split())
    a = list(map(int, input().split()))
    v1 = v2 = 1
    time = 0
    pos1 = 0
    pos2 = l
    ind1 = 0
    ind2 = n - 1

    while ind1 <= ind2:
        t1 = (a[ind1] - pos1) / v1
        t2 = (pos2 - a[ind2]) / v2

        if t1 < t2:
            time += t1
            pos1 = a[ind1]
            v1 += 1
            ind1 += 1
            pos2 -= (v2 * t1)
        elif t1 > t2:
            time += t2
            pos2 = a[ind2]
            v2 += 1
            ind2 -= 1
            pos1 += (v1 * t2)
        else:
            time += t1
            pos1 = a[ind1]
            v1 += 1
            ind1 += 1
            pos2 = a[ind2]
            v2 += 1
            ind2 -= 1
    #print('time is  ', time)
    time += (pos2 - pos1) / (v1 + v2)
    print(time)
