n = int(input())
m = input()
seq_total = 0
seq_atual = 0
m+='b'
for i in m:
    if i == 'a':
        seq_atual += 1
    else:
        if seq_atual >= 2:
            seq_total += seq_atual
        seq_atual = 0
print(seq_total)