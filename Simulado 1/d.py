'''
tem doze silver dollars e apenas 11 sao silver dollars de verdade
uma moeda eh counterfeit - ela tem peso maior ou eh lighter
ela pode fazer 3 pesagens pra achar a counterfeit se ela pesar 2 moedas
uma contra  a uotra e a balança se equilibrar entao sao verdadeiras
caso ela pesar uma dessas 2 com a falsa, ela vai saber qual eh a falsa
Input - ela identifica cada uma das moedas com as letras de A até L
sera dado duas string de letras e uma palavra up down or even
a primeira string representa as moedas da esquerda, a segunda string as moedas da direita
a terceira palavra dira se o lado direito vai up down or fica even
'''
for _ in range(int(input())):
    letters_ok = []
    possible_fakes_up = []
    possible_fakes_down = []
    for _ in range(3):
        str1, str2, word = [x for x in input().split()]
        if word == 'up':
            for i in range(len(str1)):
                if str1[i] not in letters_ok:
                    if str1[i] not in possible_fakes_down:
                        possible_fakes_down.append(str1[i])
                if str2[i] not in letters_ok:
                    if str2[i] not in possible_fakes_up:
                        possible_fakes_up.append(str2[i])
        elif word == 'down':
            for i in range(len(str1)):
                if str1[i] not in letters_ok:
                        if str1[i] not in possible_fakes_up:
                             possible_fakes_up.append(str1[i])
                if str2[i] not in letters_ok:
                        if str2[i] not in possible_fakes_down:
                            possible_fakes_down.append(str2[i])
        else:
            for i in range(len(str1)):
                if str1[i] in possible_fakes_up:
                    possible_fakes_up.remove(str1[i])
                elif str1[i] in possible_fakes_down:
                     possible_fakes_down.remove(str1[i])
                if str2[i] in possible_fakes_up:
                    possible_fakes_up.remove(str2[i])
                elif str2[i] in possible_fakes_down:
                     possible_fakes_down.remove(str2[i])
                letters_ok.append(str1[i])
                letters_ok.append(str2[i])
    print(possible_fakes_up)
    print(possible_fakes_down)
    print(f'{possible_fakes_up[0]} is the counterfeit coin and it is light.') if len(possible_fakes_up) else print(f'{possible_fakes_down[0]} is the counterfeit coin and it is heavy.')