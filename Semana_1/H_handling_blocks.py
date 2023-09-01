def is_sorted(lst):
    return all(lst[i] <= lst[i+1] for i in range(len(lst) - 1))

n, k = map(int, input().split())
dic_ordenado = {i: [] for i in range(1, k+1)}
dic_posicoes = {i: [] for i in range(1, k+1)}
lista = []
lista_geral = [0] * n

for i in range(n):
    m, c = map(int, input().split())
    lista.append(m)
    dic_ordenado[c].append(m)
    dic_ordenado[c].sort()
    dic_posicoes[c].append(i)

for k, posicoes in dic_posicoes.items():
    for posicao in posicoes:
        lista_geral[posicao] = dic_ordenado[k].pop(0)

if is_sorted(lista_geral):
    print('Y')
else:
    print('N')