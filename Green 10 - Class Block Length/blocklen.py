t1, t2 = input().split()
h1, m1 = [int(i) for i in t1.split(':')]
h2, m2 = [int(i) for i in t2.split(':')]
print((h2 * 60 + m2) - (h1 * 60 + m1))