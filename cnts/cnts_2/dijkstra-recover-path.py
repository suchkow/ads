import heapq

def dijkstra(graph, start, end):
    level = [float('inf')] * len(graph)
    previous = [-1] * len(graph)
    level[start] = 0
    heap = [(0, start)]

    while heap:
        d, u = heapq.heappop(heap)

        if d > level[u]:
            continue

        for v, w in enumerate(graph[u]):
            if w != -1 and level[u] + w < level[v]:
                level[v] = level[u] + w
                previous[v] = u
                heapq.heappush(heap, (level[v], v))

    path = list()

    u = end
    while u != -1:
        path.append(u)
        u = previous[u]

    path.reverse()

    if path[0] != start:
        return [-1]
    
    return path

n, s, f = map(int, input().split(' '))
graph = list()

for _ in range(n):
    row = list(map(int, input().split(' ')))
    graph.append(row)
    
path = dijkstra(graph, s - 1, f - 1)
if path[0] == -1:
    print(-1)
else:
    print(' '.join(str(u + 1) for u in path))
