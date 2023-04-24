N = int(input())
matrix = [list(map(int, input().split(' '))) for _ in range(N)]

for k in range(N):
    for i in range(N):
        for j in range(N):
            matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])

for i in range(N):
    for j in range(N):
        print(matrix[i][j], end=' ')
    print()