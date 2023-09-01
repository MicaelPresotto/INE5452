'''
dado os bancos e as debentures
se eh possivel que todos os bancos paguem seus debitos usando sua propria reserva e
creditos
d = debtor bank - quanto vai perder - devedor
c = creditor bank - quanto vai ganhar
v = debenture value - quanto deve
'''
while True:
    b,n = [int(x) for x in input().split()]
    if b == n == 0:
        break
    bank_list = [int(x) for x in input().split()]
    bank_list.insert(0,0)
    for i in range(n):
        d,c,v = [int(x) for x in input().split()]
        bank_list[d] -= v
        bank_list[c] += v
    for i in bank_list:
        if i < 0:
            print('N')
            break
    else:
        print('S')
    
