'''
demora 10s de um lado para o outro da escada rolante;
Se entrar no momento T vai sair no momento T+10, pode várias pessoas por vez.
se ela tentar entra no momento em que está indo pro lado que ela quer, então ela pode entrar
caso contrário, ela precisa esperar as pessoas sairem.
no person will ever arrive on the double escalator at the exact moment the escalator stops
t = momento em que ela chega na escada rolante(ou seja, momento de entrada)
d = direção da escada
'''


n = int(input())
count_time = 0
time_list  = []
direction_list = []
ultimo_valor = 0
for _ in range(n):
    t, d = [int(x) for x in input().split()]
    time_list.append(t)
    direction_list.append(d)
count_time += time_list[0]+10
for i in range(1, len(time_list)):
    if count_time < time_list[i] and direction_list[i] == direction_list[i-1] or count_time > time_list[i] and direction_list[i] != direction_list[i-1]:
        count_time+= 10
    elif count_time > time_list[i] and direction_list[i] == direction_list[i-1]:
        ultimo_valor = time_list[i]
print(count_time)
