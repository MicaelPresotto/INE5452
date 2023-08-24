
n = int(input())
input()
for i in range(n):
    dic = dict()
    lines = []
    if i > 0:
        print()
    while True:
        try:
            word = input()
            if not word:
                break
        except:
            break
        word_ordenada = ''.join(sorted(word.replace(' ', '')))
        if word_ordenada in dic:
            dic[word_ordenada].add(word)
        else:
            dic[word_ordenada] = {word}
    
    for v in dic.values():
        v = list(v)
        v.sort()

        for i in range(len(v)):
            for j in range(i+1, len(v)):
                lines.append((v[i], v[j]))
    lines.sort()
    for a,b in lines:
        print(f'{a} = {b}')
