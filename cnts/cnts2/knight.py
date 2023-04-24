from collections import deque


def read() -> list:
    return [int(i) for i in str(input()).split(' ')]


def is_reachable(k, n, j, i, m, s) -> bool:
    offsets = [(2, 1), (1, 2), (-1, 2), (-2, 1),
               (-2, -1), (-1, -2), (1, -2), (2, -1)]
    board = [[None] * n for _ in range(k)]
    board[j - 1][i - 1] = 0 #start
    
    #bfs here
    deq = deque([(j - 1, i - 1)])
    
    while deq:
        j, i = deq.popleft()

        for dj, di in offsets:
            if (0 <= (j + dj) < k) and (0 <= (i + di) < n) and board[j + dj][i + di] == None:
                board[j + dj][i + di] = board[j][i] + 1
                deq.append((j + dj, i + di))
                
    if board[m - 1][s - 1] != None:
        return True
    else:
        return False


if is_reachable(*read()):
    print('YES')
else:
    print('NO')
