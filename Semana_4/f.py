import sys

def solve(end, n, curr, prev, pieces, used):
    if curr == n - 1 and prev[1] == end[0]:
        return True
    elif curr == n - 1:
        return False

    for i in range(len(pieces)):
        if used[i]:
            continue

        used[i] = True
        p = pieces[i]
        if p[0] == prev[1]:
            ans = solve(end, n, curr + 1, p, pieces, used)
            if ans:
                return True

        p = (p[1], p[0])

        if p[0] == prev[1]:
            ans = solve(end, n, curr + 1, p, pieces, used)
            if ans:
                return True

        used[i] = False

    return False

def main():
    for line in sys.stdin:
        n = int(line)
        if n == 0:
            break

        k = int(input())
        first = tuple(map(int, input().split()))
        second = tuple(map(int, input().split()))

        pieces = []
        used = []

        for _ in range(k):
            l, r = map(int, input().split())
            pieces.append((l, r))
            used.append(False)

        if solve(second, n + 2, 1, first, pieces, used):
            print("YES")
        else:
            print("NO")

        pieces.clear()
        used.clear()

if __name__ == "__main__":
    main()
