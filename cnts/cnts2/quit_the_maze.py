from collections import deque

# Считываем входные данные
n, m = map(int, input().split())
maze = [list(map(int, input().split())) for _ in range(n)]
x1, y1, x2, y2 = map(int, input().split())

deq = deque([(x1-1, y1-1, 0)])

distances = [[-1] * m for _ in range(n)]
distances[x1-1][y1-1] = 0

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# bfs
while deq:
    x, y, d = deq.popleft()
    for i in range(4):
        if (
            (0 <= (x + dx[i]) < n) and (0 <= (y + dy[i]) < m) and
            maze[x + dx[i]][y + dy[i]] == 0 and distances[x + dx[i]][y + dy[i]] == -1
        ):
            distances[x + dx[i]][y + dy[i]] = d + 1
            deq.append((x + dx[i], y + dy[i], d + 1))

print(distances[x2-1][y2-1])
