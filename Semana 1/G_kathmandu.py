d, m, y = [int(i) for i in input().split()]
lista = [0]
for _ in range(y):
    c = int(input())
    lista.append(c)
lista.append(m)
for i in range(len(lista)-1):
    if lista[i+1] - lista[i] >= d:
        print('Y')
        break
else:
    print('N')