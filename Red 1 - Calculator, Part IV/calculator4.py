tok = input().split()[::-1]
stack = []

for i in tok:
    if i in "+-*/":
        op1 = stack.pop()
        op2 = stack.pop()

        if i == '+':
            stack.append(op1 + op2)
        elif i == '-':
            stack.append(op1 - op2)
        elif i == '*':
            stack.append(op1 * op2)
        else:
            stack.append(op1 / op2)
    else:
        stack.append(float(i))

print(format(stack.pop(), '.3f'))
