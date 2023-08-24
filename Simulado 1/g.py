case_count = 1
for _ in range(int(input())):
    x = [int(x) for x in input().split()]
    x.remove(min(x))
    x.remove(max(x))
    print(f'Case {case_count}: {x[0]}')
    case_count+=1
