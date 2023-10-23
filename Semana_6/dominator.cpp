#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


std::vector<std::vector<char>> dominators;

void dfs(int u, std::vector<std::vector<int>> &adjs, std::vector<bool> &visited) {
    visited[u] = true;
    for (int v = 0; v < adjs.size(); v++) {
        if (adjs[u][v] == 1 && !visited[v]) {
            dfs(v, adjs, visited);
        }
    }
}

int sum_vector(std::vector<int> v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum;
}

int main(void) {
    int t;
    std::cin >> t;
    int test_case = 0;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> adjs;
        std::vector<bool> visited(n);
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

        dfs(0, adjs, visited);

        // Inicialize a matriz de dominadores
        dominators.clear();
        for (int i = 0; i < n; i++) {
            std::vector<char> line = {};
            for (int j = 0; j < n; j++) {
                if (i == j && visited[i]) {
                    line.push_back('Y');
                } else {
                    line.push_back('N');
                }
            }
            dominators.push_back(line);
        }
        
        std::vector<bool> visited_2(n);
        if(sum_vector(adjs[0]) != 0){
            for (int i = 0; i < n; i++) {
                std::vector<std::vector<int>> copied_adjs = adjs;
                for (int h = 0; h < n; h++) visited_2[h] = false;
                for (int k = 0; k < n; k++) copied_adjs[i][k] = 0;
                dfs(0, copied_adjs, visited_2);
                for (int j = 0; j < n; j++) {
                    if (visited[j] && !visited_2[j]) {
                        dominators[i][j] = 'Y';
                    }
                }
            }
        }

        // Imprimir a matriz de dominadores no formato desejado
        std::cout << "Case " << ++test_case << ":" << std::endl;
        for (int i = 0; i < n; i++) {
            std::string line = "+";
            for (int j = 0; j < 2 * n - 1; j++) {
                line += '-';
            }
            line += "+";
            std::cout << line << std::endl;
            for (int j = 0; j < n; j++) {
                std::cout << "|" << dominators[i][j];
            }
            std::cout << "|" << std::endl;
        }
        std::string line = "+";
        for (int j = 0; j < 2 * n - 1; j++) {
            line += '-';
        }
        line += "+";
        std::cout << line << std::endl;
    }
}
