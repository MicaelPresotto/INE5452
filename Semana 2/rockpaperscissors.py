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
    p,m = [int(x) for x in input().split()]
    if p == 0:
        break
    for _ in range(m):
        p1,m1,p2,m2 = [x for x in input().split()]
        p1, p2 = int(p1), int(p2)


        