F, A, B = [int(i) for i in input().split()]
percentage = float(input())

if F < max(A, B) * percentage:
    if A < B:
        print('B')
    else:
        print('A')
else:
    print('F')