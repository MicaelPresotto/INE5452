t = int(input())
cont_case = 1
for _ in range(t):
    c, d = [int(x) for x in input().split()]
    conversion = 9/5*c + 32
    conversion += d
    desconversion = (conversion-32)*5/9
    print(f'Case {cont_case}: {(desconversion):.2f}')
    cont_case += 1
