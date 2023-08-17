import sys
n  = int(input())
matrix = [[0 for _ in range(11)] for _ in range(11)]
for _ in range(n):
    d,l,r,c = [int(x) for x in input().split()]
    if d == 0:
        for i in range(c, c+l):
            try:
                if matrix[r][i] == 1:
                    print('N')
                    sys.exit()
                matrix[r][i] = 1
            except IndexError:
                print('N')
                sys.exit()
    else:
        for i in range(r, r+l):
            try:
                if matrix[i][c] == 1:
                    print('N')
                    sys.exit()
                matrix[i][c] = 1
            except IndexError:
                print('N')
                sys.exit()
print('Y')
