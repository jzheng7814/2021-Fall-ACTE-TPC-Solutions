A, B, op = input().split()
A = int(A)
B = int(B)

if op == '+':
    print(A + B)
elif op == '-':
    print(A - B)
elif op == '*':
    print(A * B)
else:
    print(int(A / B))