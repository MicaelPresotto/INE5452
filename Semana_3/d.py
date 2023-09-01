while True:
    n = int(input())
    if n == 0:
        break
    pilha = [int(x) for x in range(n,0,-1)]
    descartadas = []
    while len(pilha) >= 2:
        descartadas.append(pilha.pop())
        pilha.insert(0, pilha.pop())

    if n == 1:
        print('Discarded cards:', end= '')
        print()
        print('Remaining card: ', end='')
        print(*pilha)
    else:
        print('Discarded cards: ', end= '')
        print(*descartadas, sep=', ')
        print('Remaining card: ', end='')
        print(*pilha)