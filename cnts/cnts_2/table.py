from collections import deque

n, m = map(int, input().split(' '))
input = [list(map(int, input().split(' '))) for _ in range(n)]

mat = [[n + m] * m for _ in range(n)]

deq = deque()
for i in range(n):
    for j in range(m):
        if input[i][j] == 1:
            deq.append((i, j))
            mat[i][j] = 0

while deq:
    i, j = deq.popleft()
    for di, dj in ((-1, 0), (1, 0), (0, -1), (0, 1)):
        if 0 <= i + di < n and 0 <= j + dj < m and mat[i + di][j + dj] == n + m:
            mat[i + di][j + dj] = mat[i][j] + 1
            deq.append((i + di, j + dj))

print(*[row for row in mat])