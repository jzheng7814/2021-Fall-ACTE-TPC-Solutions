stack = []
st = input()

for i in st:
    if i == '(':
        stack.append('(')
    else:
        if len(stack) == 0:
            print('F')
            exit(0)
        else:
            stack.pop()

if len(stack) == 0:
    print('T')
else:
    print('F')