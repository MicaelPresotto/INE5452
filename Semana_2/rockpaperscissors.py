first = True
while True:
    try:
        p, k = map(int, input().split())
    except ValueError:
        break
    if first:
        first = False
    else:
        print()
    wins = [0] * p
    loses = [0] * p
    n = k * p * (p - 1) // 2
    
    for _ in range(n):
        p1, m1, p2, m2 = input().split()
        p1, p2 = int(p1), int(p2)
        if m1 == m2:
            continue
        elif (m1, m2) in [('rock', 'scissors'), ('paper', 'rock'), ('scissors', 'paper')]:
            wins[p1-1] += 1
            loses[p2-1] += 1
        else:
            wins[p2-1] += 1
            loses[p1-1] += 1
    
    for i in range(len(wins)):
        if wins[i] + loses[i] == 0:
            print('-')
        else:
            print(f'{wins[i]/ (wins[i] + loses[i]):.3f}')