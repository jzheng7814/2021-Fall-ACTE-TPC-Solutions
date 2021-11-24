N = int(input())
movies = sorted([[int(i) for i in input().split()] for j in range(N)], key = lambda i: i[1])
count = 0
time = 0

while len(movies) > 0:
    time = movies[0][1]
    count += 1
    while len(movies) > 0 and movies[0][0] < time:
        movies.pop(0)

print(count)