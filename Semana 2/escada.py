tuples = []
for _ in range(int(input())):
    t, d = [int(x) for x in input().split()]
    tuples.append((t,d))
curr_time = tuples[0][0] + 10
curr_dir = tuples[0][1]
i = 1
other_dir = False
other_time = 0
while i < len(tuples):
    while i < len(tuples) and tuples[i][0] < curr_time:
        if tuples[i][1] != curr_dir:
            other_dir = True
            other_time = tuples[i][0]
        else:
            curr_time = tuples[i][0] + 10
        i += 1

    if  i == len(tuples):
        continue

    if other_dir:
        other_dir = False
        curr_time = max(curr_time, other_time) + 10
        other_time = 0
        curr_dir = (curr_dir+1)%2
    if tuples[i][0] > curr_time:
        if tuples[i][1] == curr_dir:
            curr_time = tuples[i][0] + 10
        else:
            other = True
            other_time = tuples[i][0]
if other_dir:
    other_dir = False
    curr_time = max(curr_time, other_time) + 10
    curr_dir = (curr_dir+1)%2
print(curr_time)

