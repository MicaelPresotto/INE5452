#include <iostream>
#include <vector>
#include <algorithm>

bool safe(const std::vector<std::vector<int>>& matrix, int row, int col) {
    int n = matrix.size();

    // Verificando se há alguma rainha na mesma linha ou coluna
    for (int i = 0; i < n; i++) {
        if (matrix[i][col] == 1) {
            return false;
        }
    }

    // Diagonal inferior direita
    int i = row + 1, j = col + 1;
    while (i < n && j < n) {
        if (matrix[i][j] == 1) {
            return false;
        }
        i++;
        j++;
    }

    // Diagonal inferior esquerda
    i = row + 1, j = col - 1;
    while (i < n && j >= 0) {
        if (matrix[i][j] == 1) {
            return false;
        }
        i++;
        j--;
    }

    // Diagonal superior direita
    i = row - 1, j = col + 1;
    while (i >= 0 && j < n) {
        if (matrix[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }

    // Diagonal superior esquerda
    i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) {
        if (matrix[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }
    return true;
}

bool all_safe(const std::vector<std::vector<int>>& matrix) {
    return std::all_of(matrix.begin(), matrix.end(), [](const std::vector<int>& row) {
        return std::all_of(row.begin(), row.end(), [](int value) { return value != 1; });
    });
}

int solve(std::vector<std::vector<int>>& matrix, std::vector<std::pair<int, int>>& queens, std::vector<bool>& used, int col) {
    int n = matrix.size();
    if (col == 8) {
        if (all_safe(matrix)) {
            return 0;
        }
        return 2e9;
    }
    int min = 2e9;
    auto[qi, qj] = queens[col];
    for (int row = 0; row < 8; row++) {
        if (used[row]) continue;
        if (!safe(matrix, row, qj)) continue;
        used[row] = true;
        queens[col].first = row;
        matrix[row][qj] = 1;
        int solved = solve(matrix, queens, used, col + 1);
        if (row != qi) solved++;
        min = std::min(min, solved);
        matrix[row][qj] = 0;
        queens[col].first = qi;
        used[row] = false;
    }
    return min;
}

int main(void) {
    int caso = 1;
    for (;;) {
        std::vector<std::vector<int>> matrix(8, std::vector<int>(8, 0));
        std::vector<std::pair<int, int>> queens;
        std::vector<bool> used;
        for (int i = 0; i < 8; i++) {
            int k; std::cin >> k;
            queens.push_back(std::make_pair(k - 1, i));
            used.push_back(false);
        }
        if (std::cin.eof()) break;
        int min = solve(matrix, queens, used, 0);
        std::cout << "Case " << caso++ << ": " << min << std::endl;
    }
    return 0;
}
