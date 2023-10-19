#include <iostream>
#include <vector>
#include <algorithm>

std::vector<bool> visited(100);
std::vector<std::vector<char>> dominators;

void dfs(int u, std::vector<std::vector<int>> &adjs) {
    visited[u] = true;
    for (int v = 0; v < adjs.size(); v++) {
        if (adjs[u][v] == 1 && !visited[v]) {
            dfs(v, adjs);
        }
    }
}

int main(void) {
    int t;
    std::cin >> t;
    int test_case = 0;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> adjs;
        for (int i = 0; i < n; i++) {
            visited.push_back(false);
            std::vector<int> line = {};
            for (int j = 0; j < n; j++) {
                int x;
                std::cin >> x;
                line.push_back(x);
            }
            adjs.push_back(line);
        }

        dominators.clear();
        for (int i = 0; i < n; i++) {
            std::vector<char> line;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    line.push_back('Y');
                } else {
                    line.push_back('N');
                }
            }
            dominators.push_back(line);
        }

        dfs(0, adjs);

        for (int i = 1; i < n; i++) {
            std::vector<std::vector<int>> copied_adjs = adjs;
            for (int h = 0; h < n; h++) visited[h] = false;
            for (int k = 0; k < n; k++) copied_adjs[i][k] = 0;
            dfs(0, copied_adjs);
            for (int j = 1; j < n; j++) {
                if (!visited[j]) {
                    dominators[i][j] = 'Y';
                }
            }
        }

        // Imprimir a matriz de dominadores no formato desejado
        std::cout << "Case " << ++test_case << ":" << std::endl;
        for (int i = 0; i < 2 * n + 1; i++) {
            for (int j = 0; j < 2 * n + 1; j++) {
                if (i % 2 == 0) {
                    if (j % 2 == 0) {
                        std::cout << '+';
                    } else {
                        std::cout << '-';
                    }
                } else {
                    if (j % 2 == 0) {
                        std::cout << '|';
                    } else {
                        std::cout << dominators[i / 2][j / 2];
                    }
                }
            }
            std::cout << std::endl;
        }
    }
}
