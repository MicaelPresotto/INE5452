c = int(input())
lista = []
largest_balances = []
valor = 100
for _ in range(c):
    secret_number = int(input())
    lista.append(secret_number)

for i in range(len(lista)):
    valor+=lista[i]
    largest_balances.append(valor)


print(max(largest_balances)) if max(largest_balances) > 100 else print(100)