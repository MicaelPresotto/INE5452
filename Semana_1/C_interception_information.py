n = [int(x) for x in input().split()]
for i in n:
    if i != 0 and i != 1:
        print('F')
        break
else:
    print('S')