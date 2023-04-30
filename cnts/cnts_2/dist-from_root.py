from collections import deque

def read() -> list:
    n = int(input())
    adjacents = [[] for _ in range(n + 1)]

    for i in range(2, n + 1):
        parent = int(input())
        adjacents[parent].append(i)

    return adjacents

def bfs(s, adjacents: list) -> list:
    deq = deque([s])
    levels = [-1] * (len(adjacents))
    levels[s] = 0

    while deq:
        node = deq.popleft()

        for i in adjacents[node]:
            if levels[i] == -1:
                levels[i] = levels[node] + 1
                deq.append(i)

    return levels

d = bfs(1, read())

print(f'{ max(d[1:]) }\n{ d.count(max(d[1:])) }')
print(*[n for n in range(1, len(d)) if d[n] == max(d[1:])])
