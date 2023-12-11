from queue import Queue

class Edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w

class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.rank = [1] * n

    def find_set(self, i):
        if self.p[i] == i:
            return i
        parent = self.find_set(self.p[i])
        self.p[i] = parent
        return parent

    def same(self, i, j):
        return self.find_set(i) == self.find_set(j)

    def union_set(self, i, j):
        pi = self.find_set(i)
        pj = self.find_set(j)

        if pi == pj:
            return

        if self.rank[pi] > self.rank[pj]:
            pi, pj = pj, pi

        self.p[pi] = pj
        self.rank[pj] += self.rank[pi]

def kruskal(edges, V):
    edges.sort(key=lambda x: x.w)
    n = 0
    ret = 0
    uf = UnionFind(V)
    adj = [[] for _ in range(V)]

    for i in range(len(edges)):
        e = edges[i]
        if uf.same(e.u, e.v):
            continue

        adj[e.u].append((e.v, e.w))
        adj[e.v].append((e.u, e.w))

        uf.union_set(e.u, e.v)
        ret += e.w
        n += 1

        if n == V - 1:
            break

    return adj

def bfs(adj, s, t):
    q = Queue()
    q.put(s)
    visited = [False] * len(adj)
    visited[s] = True
    d = [-1e9] * len(adj)

    while not q.empty():
        u = q.get()

        for v, w in adj[u]:
            if v == t:
                return max(d[u], w)
            if visited[v]:
                continue

            visited[v] = True
            d[v] = max(d[u], w)
            q.put(v)

    return -1e9

def main():
    t = 0

    while True:
        c, s, q = map(int, input().split())
        if c == s == q == 0:
            break

        if t > 0:
            print()

        edges = []
        for _ in range(s):
            x, y, w = map(int, input().split())
            x -= 1
            y -= 1
            edges.append(Edge(x, y, w))
            edges.append(Edge(y, x, w))

        adj = kruskal(edges, c)

        print(f"Case #{t + 1}")
        for _ in range(q):
            a, b = map(int, input().split())
            a -= 1
            b -= 1
            ans = bfs(adj, a, b)

            if ans > 0:
                print(ans)
            else:
                print("no path")

        t += 1

if __name__ == "__main__":
    main()
