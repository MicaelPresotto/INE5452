'''
achar os angulos do relogio entre os ponteiros dado o horario no input
Formula: 30 eh o angulo de uma hora no relogio, o 11/2 se da para o ajuste do angulo a cada minuto que passa
pois quando o ponteiro maior move o menor tambem move.
'''
while True:
    n = input()
    if n == '0:00':
        break
    n = n.split(':')
    minutos = int(n[1])
    horas = int(n[0])
    formula = abs(11*minutos/2 - 30 * horas)
    if formula > 180:
        formula = 360 - formula
    print(f'{formula:.3f}')