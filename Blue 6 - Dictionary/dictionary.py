N, M = [int(i) for i in input().split()]
dc = {}

for i in range(N):
    words = input().split()
    dc[words[0]] = ' '.join(words[1:])

for i in range(M):
    print(dc[input()])