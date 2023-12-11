
import math
from queue import Queue

class Edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w

def find_set(parents, i):
    if parents[i] == i:
        return i
    root = find_set(parents, parents[i])
    parents[i] = root
    return root

def union_sets(parents, ranks, i, j):
    pi = find_set(parents, i)
    pj = find_set(parents, j)

    if pi == pj:
        return

    if ranks[pi] > ranks[pj]:
        pi, pj = pj, pi

    parents[pi] = pj
    ranks[pj] += ranks[pi]

def kruskal(edges, vertices):
    edges.sort(key=lambda e: e.w)

    n = 0
    parents = list(range(vertices))
    ranks = [1] * vertices
    adj = [[] for _ in range(vertices)]

    for e in edges:
        if n >= vertices - 1:
            break

        if find_set(parents, e.u) == find_set(parents, e.v):
            continue

        adj[e.u].append((e.v, e.w))
        adj[e.v].append((e.u, e.w))

        union_sets(parents, ranks, e.u, e.v)
        n += 1

    return adj

def bfs(adjacency, start, target):
    q = Queue()
    q.put(start)
    visited = [False] * len(adjacency)
    visited[start] = True
    distances = [-1e9] * len(adjacency)

    while not q.empty():
        current_node = q.get()

        for neighbor, weight in adjacency[current_node]:
            if neighbor == target:
                return max(distances[current_node], weight)
            if visited[neighbor]:
                continue

            visited[neighbor] = True
            distances[neighbor] = max(distances[current_node], weight)
            q.put(neighbor)

    return -1e9

def calculate_distance(point_a, point_b):
    return math.sqrt((abs(point_a[0] - point_b[0]))**2 + (abs(point_a[1] - point_b[1]))**2)

def main():
    test_case = 0
    first = True
    while True:
        if first:
            first = False
        else:
            trash = input()
        vertices = int(input())
        if vertices == 0:
            break

        coordinates = []
        for _ in range(vertices):
            x, y = map(int, input().split())
            coordinates.append((x, y))

        edges = []
        for i in range(vertices):
            for j in range(i + 1, vertices):
                dist = calculate_distance(coordinates[i], coordinates[j])
                edges.append(Edge(i, j, dist))
                edges.append(Edge(j, i, dist))

        adjacency_list = kruskal(edges, vertices)
        result = bfs(adjacency_list, 0, 1)
        print(f"Scenario #{test_case + 1}\nFrog Distance = {result:.3f}\n")
        test_case += 1

if __name__ == "__main__":
    main()
