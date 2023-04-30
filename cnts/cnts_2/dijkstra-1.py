import heapq

def dijkstra(graph, start, end):
    levels = {node: float('inf') for node in graph}
    levels[start] = 0
    pq = [(0, start)]
    
    while pq:
        curr_level, curr_node = heapq.heappop(pq)
        
        if curr_node == end:
            return curr_level
        
        if curr_level > levels[curr_node]:
            continue
        
        for neighbor, weight in graph[curr_node].items():
            new_level = curr_level + weight

            if new_level < levels[neighbor]:
                levels[neighbor] = new_level
                heapq.heappush(pq, (new_level, neighbor))
    return -1


n, s, f = map(int, input().split(' '))
graph = dict()

for i in range(n):
    row = list(map(int, input().split(' ')))
    graph[i+1] = {j+1: weight for j, weight in enumerate(row)}

print(dijkstra(graph, s, f))
