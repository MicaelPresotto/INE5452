'''
O valor da carta é definido como o valor da face da carta se
a carta ter um numero de 2 a 9, otherwise o valor eh 10
Há uma pilha com 52 cartas viradas pra baixo
Pegue as primeiras 25 cartas da pilha
Coloque Y = 0 e depoi execute 3 vezes o seguinte step
Pega a carta do topop da pilha e determine seu valor
O valo da carta é X, adicione isso a Y
Coloque essa carta e as (10-X) cartas do topo da pilha fora
Pelo menos coloque as 25 cartas restantes em sua mao no topo da pilha
A tarefa é pra determinar a Y-th carta da pilha, contado desde baixo(bottom)
Input
Um intenro o numero de testes
Cada caso consiste em 52 cartas dadas na ordem inicial da pilha 
from bottom to top
O formato de cada string eh 2 caracteres, indicando o valor e o naipe
Output
Para cada caso de teste print a carta alvo.
'''
n = int(input())
count_case = 1
for _ in range(n):
    mao = []
    while len(pilha) <= 52:
        pilha = [x for x in input().split()]
        #TODO: arrumar input para até no máximo 52 linhas
    for _ in range(25):
        mao.append(pilha.pop())
    y = 0
    for _ in range(3):
        topo = pilha.pop()
        if topo[0] not in ('A','Q','K','J'):
            x = int(topo[0])
        else:
            x = 10
        y = x + y
        for i in range(10-x):
            pilha.pop()
    for _ in range(25):
        pilha.append(mao.pop())
    print(f'Case {count_case}: {pilha[y-1]}')
    count_case += 1
        