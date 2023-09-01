t = int(input()) #numero de test cases
oudlers_kings = 4.5
queens = 3.5
knights = 2.5
jacks = 1.5
normal_cards = 0.5
oudler_3 = 36
oudler_2 = 41
oudler_1 = 51
no_oudler = 56
hand = 1
lista_prints = []
for _ in range(t): 
    m = int(input()) #numero de carta ganha pelo taker
    total = 0
    n_oudlers = 0
    for _ in range(m):
        card = input().split(' ')
        if card[0] != 'fool':
            if card[2] == 'trumps' and card[0] == 'twenty-one' or card[2] == 'trumps' and card[0] == 'one':
                n_oudlers += 1
                total += oudlers_kings
            else:
                if card[0] not in ('knight', 'jack', 'king', 'queen'):
                    total += normal_cards
                else:
                    if card[0] == 'knight':
                        total += knights
                    elif card[0] == 'king':
                        total += oudlers_kings
                    elif card[0] == 'queen':
                        total += queens
                    elif card[0] == 'jack':
                        total += jacks
        else:
            n_oudlers += 1
            total += oudlers_kings
    if n_oudlers == 1:
        points = total - oudler_1
        points = int(points)
        if points >= 0:
            lista_prints.append(f'Game won by {points} point(s).')
        else:
            lista_prints.append(f'Game lost by {-1*points} point(s).')

    elif n_oudlers == 2:
        points = total - oudler_2
        points = int(points)
        if points >= 0:
            lista_prints.append(f'Game won by {points} point(s).')
        else:
            lista_prints.append(f'Game lost by {-1*points} point(s).')
    elif n_oudlers == 3:
        points = total - oudler_3
        points = int(points)
        if points >= 0:
            lista_prints.append(f'Game won by {points} point(s).')
        else:
            lista_prints.append(f'Game lost by {-1*points} point(s).')
    else:
        points = total - no_oudler
        points = int(points)
        if points >= 0:
            lista_prints.append(f'Game won by {points} point(s).')
        else:
            lista_prints.append(f'Game lost by {-1*points} point(s).')
for i in range(len(lista_prints)):
    print(f'Hand #{hand}')
    hand+=1
    print(lista_prints[i])
    if i == len(lista_prints) - 1:
        ...
    else:
        print()