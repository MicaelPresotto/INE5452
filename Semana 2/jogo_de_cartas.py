'''
Cada carta vale seu valor e o rei e rainha e a dama valem 10
O jogador com mais pontos vence se nao exceder 23.
No começo do jogo o baralho está embaralhado e as cartas estão numa pilha e cada jogador
recebe 2 cartas.
Os próximos rounds acontecem enquanto tiver players ativos.
Uma carta é pega da pilha e é contada para todos os jogadores. Se alguem exceder, tá fora
O ganhador é aquele que tem um total de 23 pontos ou se ele é o único ativo no fim.
No input teremos o N numero de rounds que ja foi jogado
I é o inteiro da carta
Dama - 11, Rainha - 12, Rei - 13 mas todos valem 10 pontos
Segunda linha do input tem 2 inteiros descrevendo as 2 cartas iniciais do John
A terceira linha a mesma coisa para Mary
A quarta linha tem N inteiros descrevendo as cartas que foram colocadas na mesa
Output
O programa deve imprimer o valor da menor carta para que Mary seja vencedora do jogo
Caso ela não consiga ganhar no próximo round, então é -1
'''
import sys
cartas_john = 0
cartas_mary = 0
n = int(input())
j1, j2 = [int(x) for x in input().split()]
cartas_john += j1 + j2
m1,m2 = [int(x) for x in input().split()]
cartas_mary += m1+m2
c = [int(x) for x in input().split()]
for i in c:    
    if i >= 11:
        cartas_john += 10
        cartas_mary += 10
    else:
        cartas_john += i
        cartas_mary += i
    if cartas_john == 23 or cartas_mary > 23 or cartas_mary + 10 < 23:
        print(-1)
        sys.exit()
if cartas_john > cartas_mary:
    print(24-cartas_john)
    sys.exit()
print(23 - cartas_mary)