from math import gcd

for i in range(int(input())):
    x1, y1, x2, y2 = [int(j) for j in input().split()]
    gcd1 = gcd(x1, y1)
    gcd2 = gcd(x2, y2)
    x1 = x1 / gcd1
    y1 = y1 / gcd1
    x2 = x2 / gcd2
    y2 = y2 / gcd2

    if x1 == x2 and y1 == y2:
        print('T')
    else:
        print('F')