'''
pedra ganha de tesoura
tesoura ganha de papel
papel ganha de pedra
se escolherem igual, ngm ganha nem perde mas nem todo mundo vai ganhar ou perder se ninguem ganhar ou perder
w - games won
l - games lost
p1_wins = rock-scissors paper-rock scissors-paper
'''
game = ['rock', 'paper', 'scissors']
while True:
    try:
        p,k = [int(x) for x in input().split()]
    except ValueError:
        break
    points_players = [0 for i in range(p)]
    points_players.insert(0,0)
    for _ in range(k):
        p1,m1,p2,m2 = [x for x in input().split()]
        p1, p2 = int(p1), int(p2)
        if m1 == game[0] and m2 == game[2] or m1 == game[1] and m2 == game[0] or m1==game[2] and m2 == game[1]:
            points_players[p1] += 1
        elif m1 == m2:
            continue
        else:
            points_players[p2] += 1

    for i in range(1, len(points_players)):
        try:
            print(f'{points_players[i]/(sum(points_players)):.3f}')
        except Exception:
            print('-')
    print()