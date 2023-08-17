n = int(input())
for _ in range(n):
    x, y = [int(x) for x in input().split()]
    reversed_x, reversed_y = str(x)[::-1], str(y)[::-1]
    sum_of_reversed = int(reversed_x) + int(reversed_y)
    reversed_sum = str(sum_of_reversed)[::-1]
    int_sum = int(reversed_sum)
    print(int_sum)