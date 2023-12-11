def solve_code(code, index, solutions, current_solution, mapping):
    if index >= len(code):
        solutions.append(current_solution)
        return

    while index < len(code) and code[index] == '0':
        index += 1

    if index >= len(code):
        return

    current_char = code[index]

    if current_char in mapping:
        current_solution += mapping[current_char]
        solve_code(code, index + 1, solutions, current_solution, mapping)
        current_solution = current_solution[:-1]

        if index == len(code) - 1:
            return

    if index == len(code) - 1:
        return

    next_char = current_char + code[index + 1]

    if next_char in mapping:
        current_solution += mapping[next_char]
        solve_code(code, index + 2, solutions, current_solution, mapping)
        current_solution = current_solution[:-1]


def main():
    t = 0
    while True:
        n = int(input())
        if n == 0:
            break

        print(f"Case #{t + 1}")
        t += 1

        mapping = {}
        for _ in range(n):
            c, code = input().split()
            mapping[code] = c

        encrypted_code = input()

        solutions = []
        solve_code(encrypted_code, 0, solutions, "", mapping)
        solutions.sort()

        for i in range(min(100, len(solutions))):
            print(solutions[i])

        print()


if __name__ == "__main__":
    main()
