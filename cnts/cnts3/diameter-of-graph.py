N = int(input())
matrix = [list(map(int, input().split())) for _ in range(N)]

dist = [float('inf')] * N

dist[0] = 0
for i in range(N):
    for u in range(N):
        for v in range(N):
            if matrix[u][v] != -1 and dist[u] != float('inf') and dist[u] + matrix[u][v] < dist[v]:
                dist[v] = dist[u] + matrix[u][v]

d = 0
r = float('inf')
for i in range(N):
    for j in range(N):
        if matrix[i][j] != -1:
            d = max(d, dist[i] + matrix[i][j] + dist[j])
            r = min(r, max(dist[i], dist[j]))

print(d)
if r != float('inf'):
    print(r)
else:
    print(0)
