from collections import deque

def min_knight_moves(start_x, start_y, target_x, target_y):
    # define the moves
    moves = [
        (-2, -1), (-2, 1), (-1, -2), (-1, 2),
        (1, -2), (1, 2), (2, -1), (2, 1)
    ]

    visited = set()
    visited.add((start_x, start_y))
    q = deque([(start_x, start_y, 0)])

    while q:
        curr_x, curr_y, steps = q.popleft()

        if curr_x == target_x and curr_y == target_y:
            return steps
        
        for move in moves:
            new_x = curr_x + move[0]
            new_y = curr_y + move[1]

            if (new_x, new_y) not in visited and 1 <= new_x <= 8 and 1 <= new_y <= 8:
                q.append((new_x, new_y, steps+1))
                visited.add((new_x, new_y))

    return -1
    
start_x, start_y = 2, 1
target_x, target_y = 8, 5
result=  min_knight_moves(start_x, start_y, target_x, target_y)

print(result)