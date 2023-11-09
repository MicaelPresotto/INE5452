import math

def obterArestas(G):
    arestas = []
    for i in range(len(G)):
        for j in range(len(G)):
            if G[i][j] != 0:
                arestas.append((i,j))
    return arestas

def obtemPeso(G, u, v):
    return G[u][v]

def busca(G) -> (float):
    # Estrutura para identificacao da arvore em cada vertice
    A = set()
    S = [{i} for i in range(len(G))]

    # Criando um dicionario que mapeia aresta para peso ordenado de acordo com o peso
    arestas = obterArestas(G)

    arestas_para_peso = dict()

    for i in arestas:
        arestas_para_peso[i] = obtemPeso(G, i[0], i[1])
    
    arestas_para_peso_ordenada = dict(sorted(arestas_para_peso.items(), key=lambda item: item[1]))\


    # Define um valor inicial a variável que indica parada (numero_de_arestas_adicionadas) e
    # o peso da arvora mínima
    numero_de_arestas_adicionadas = 0
    peso = 0

    # Cria interativamente a arvore mínima geradora
    for u, v in arestas_para_peso_ordenada.keys():

        # Se não tiver um ciclo, então adiciona a aresta a arvore e atualiza as arvores de S
        if S[u] != S[v]:
            numero_de_arestas_adicionadas += 1 # 
            A.add((u,v))
            x = S[u].union(S[v])

            for y in x:
                S[y] = x

            peso += arestas_para_peso_ordenada[(u,v)]

        # Se adicionou número de vertices - 1 arestas, então termina o algoritmo
        if numero_de_arestas_adicionadas == len(G) - 1:
            break

    return peso

def distancia(x1,x2,y1,y2):
    return math.sqrt((x1-x2)**2+(y1-y2)**2)

n = int(input())
out = input()
first = True
while(n > 0):
    if(first):
        first = False
    else:
        print()
        out = input()
    m = int(input())
    pontos = []
    while(m>0):
        x,y = map(float,input().split())
        pontos.append((x,y))
        m-=1
    adjacent_matrix = []
    for i in range(len(pontos)):
        linha = []
        for j in range(len(pontos)):
            linha.append(distancia(pontos[i][0],pontos[j][0],pontos[i][1],pontos[j][1]))
        adjacent_matrix.append(linha)
    peso = busca(adjacent_matrix)
    print(f'{peso:.2f}')
    n-=1
    
    

