import sys
si = sys.stdin.readline
n = int(si())
l = sorted([int(e) for e in si().split()])
if l[0] < 0 and l[-1] <= 0:
    print(l[-2], l[-1])
elif l[0] >= 0 and l[-1] > 0:
    print(l[0], l[1])
else:
    s, e, diff = 0, n-1, int(2e9+1)
    s1, s2 = l[s], l[e]
    while s < e:
        temp = l[s]+l[e]
        if abs(temp) < diff:
            diff = abs(temp)
            s1, s2 = l[s], l[e]
            if not temp:
                break
        if temp > 0:
            e -= 1
        else:
            s += 1
    print(s1, s2)
