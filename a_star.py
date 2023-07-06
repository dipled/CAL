# Trio: Elian Babireski, Luigi Boscatto e Pedro Vargas

class node:
    def __init__(self, coordinate: tuple, parent = None, g = 0, h = 0):
            self.coordinate = coordinate
            self.parent = parent
            self.g = g
            self.h = h
            self.f = g + h

    def __eq__(self, other):
        return self.coordinate == other.coordinate
    
    def __hash__(self):
        return hash(self.coordinate)

    def __repr__(self):
        return str(self.coordinate)

    def __str__(self):
        return str(self.coordinate)
    
    def __sub__(self, other):
        a, b = self.coordinate
        x, y = other
        return (a - x, b - y)

def manhattan(a, b):
    w, x = a
    y, z = b
    return abs(w - y) + abs(x - z)

def neighbors(maze, a):
    neighborhood = []
    for (x, y) in [a - offset for offset in [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]]:
        if x in range(0, len(maze)) and y in range(0, len(maze[0])) and maze[x][y] == 1:
            neighborhood.append(node((x, y), parent = a))
    return neighborhood

def diagonal(a, b):
    xₐ, yₐ = a   
    xᵦ, yᵦ = b
    return True if abs(xₐ - xᵦ) == 1 and abs(yₐ - yᵦ) == 1 else False

def astar(maze, start, goal, heuristic):
    frontier = [node(start)]
    interior = {node(start)}
    
    while frontier:
        current = frontier.pop()
        
        if current.coordinate == goal:
            path = []
            while current:
                path.append(current.coordinate)
                current = current.parent
            return path[::-1] 
             
        for neighbor in neighbors(maze, current):
            if neighbor in interior:
                continue

            neighbor.g = current.g + 1.4 if diagonal(neighbor.coordinate, current.coordinate) else current.g + 1
            neighbor.h = heuristic(neighbor.coordinate, goal)
            neighbor.f = neighbor.g + neighbor.h

            if neighbor not in frontier:
                frontier.append(neighbor)
                interior.add(neighbor)

            else:
                i = frontier.index(neighbor)
                if neighbor.g < frontier[i].g:
                    frontier[i] = neighbor

        frontier.sort(key = lambda x : -x.f)
    return None

maze  = [[1, 1, 1, 1, 1, 1, 1], [1, 1, 1, 0, 1, 1, 1], [1, 1, 1, 0, 1, 1, 1], [1, 1, 1, 0, 1, 1, 1], [1, 1, 1, 1, 1, 1, 1]]
start = (2, 1)
goal  = (2, 5)

print(astar(maze, start, goal, manhattan))
