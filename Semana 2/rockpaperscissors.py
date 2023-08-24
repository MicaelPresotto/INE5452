while True:
    try:
        p, k = map(int, input().split())
    except ValueError:
        break
    
    points_players = [0] * p
    n = k * p * (p - 1) // 2
    
    for _ in range(n):
        p1, m1, p2, m2 = input().split()
        p1, p2 = int(p1), int(p2)
        if m1 == m2:
            continue
        elif (m1, m2) in [('rock', 'scissors'), ('paper', 'rock'), ('scissors', 'paper')]:
            points_players[p1-1] += 1
        else:
            points_players[p2-1] += 1
    
    total_points = sum(points_players)
    for points in points_players:
        try:
            print(f'{points / total_points:.3f}')
        except:
            print('-')
    print()
#TODO: fazer em cpp