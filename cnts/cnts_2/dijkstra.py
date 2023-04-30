import heapq

def dijkstra(graph, start, end) -> int:
    n = len(graph)
    levels = [float('inf')] * n
    levels[start] = 0
    heap = [(0, start)]

    while heap:
        (level, node) = heapq.heappop(heap)

        if node == end:
            return level
        
        if level > levels[node]:
            continue

        for neighbor, weight in enumerate(graph[node]):
            if weight == -1:
                continue

            if level + weight < levels[neighbor]:
                levels[neighbor] = level + weight
                heapq.heappush(heap, (level + weight, neighbor))
    return -1

n, start, end = map(int, input().split(' '))
graph = [list(map(int, input().split(' '))) for _ in range(n)]

distance = dijkstra(graph, start - 1, end - 1)
print(distance)
