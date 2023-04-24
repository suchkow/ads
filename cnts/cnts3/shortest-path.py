n, m, s = map(int, input().split())

INF = float('inf')
dist = [[INF] * n for _ in range(n)]
for i in range(n):
    dist[i][i] = 0

for _ in range(m):
    u, v, w = map(int, input().split())
    dist[u-1][v-1] = min(dist[u-1][v-1], w)

for k in range(n):
    for i in range(n):
        for j in range(n):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

for i in range(n):
    if dist[s-1][i] == INF:
        print('*')
    elif dist[s-1][i] == -INF:
        print('-')
    else:
        print(dist[s-1][i])
