'''
O urso só entende palavras que são palindromos
'''
while True:
    x = input().lower()
    if x == 'done':
        break
    x_pontuactions = ['.', ',', '!', '?']
    for i in x_pontuactions:
        x = x.replace(i, '')
    x = x.replace(' ', '')
    x_palindrome = x[::-1]
    if x == x_palindrome:
        print("You won't be eaten!")
    else:
        print('Uh oh..')