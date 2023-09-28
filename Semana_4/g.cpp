#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

bool areEqualVectors(const std::vector<int>& lista1, const std::vector<int>& lista2) {
    if (lista1.size() != lista2.size()) {
        return false;
    }

    for (size_t i = 0; i < lista1.size(); ++i) {
        if (lista1[i] != lista2[i]) {
            return false;
        }
    }

    return true;
}

void removeRepeatedVectors(std::vector<std::vector<int>>& matriz) {
    size_t tamanhoMatriz = matriz.size();

    // Percorra a matriz e compare cada lista com todas as listas subsequentes
    for (size_t i = 0; i < tamanhoMatriz - 1; ++i) {
        for (size_t j = i + 1; j < tamanhoMatriz; ++j) {
            if (areEqualVectors(matriz[i], matriz[j])) {
                // Remove a lista repetida
                matriz.erase(matriz.begin() + j);
                --j; // Volte uma posição após a remoção
                --tamanhoMatriz; // Atualize o tamanho da matriz
            }
        }
    }
}

bool comparadorDecrescente(const std::vector<int>& a, const std::vector<int>& b) {
    // Compare os elementos do vetor a e b na ordem inversa (decrescente)
    return a > b;
}

std::vector<std::vector<int>> solve(std::vector<std::vector<int>> matrix, int result){
    std::vector<std::vector<int>> answers;
    for(int i = 0; i < matrix.size(); i++){
        int soma = 0;
        std::vector<int> answer;
        for(int j = 0; j < matrix[i].size(); j++){
            soma += matrix[i][j];
            answer.push_back(matrix[i][j]);
        }
        if(soma == result){
            answers.push_back(answer);
        }
    }
    return answers;
}

int main(void){
    for(;;){
        int t, n; std::cin >> t >> n;
        if (n == 0 && t == 0) break;
        std::vector<int> x(n);
        for(int i = 0; i < n; i++){
            std::cin >> x[i];
        }
        std::bitset<13> conjunto;
        std::vector<std::vector<int>> matrix;
        for(int i = 0; i < (1 << n); i++){
            conjunto = i;
            std::vector<int> line;
            for(int j = 0; j < n; j++){
                if(conjunto[j]){
                    line.push_back(x[j]);
                }
            }
            matrix.push_back(line);
        }
        std::vector<std::vector<int>> answers = solve(matrix, t);
        if(answers.size() == 0){
            std::cout << "Sums of " << t << ":" << std::endl;
            std::cout << "NONE" << std::endl;
        }else{
            std::cout << "Sums of " << t << ":" << std::endl;
            removeRepeatedVectors(answers);
            std::sort(answers.begin(), answers.end(), comparadorDecrescente);
            for(int i = 0; i < answers.size(); i++){
                bool first = true;
                for(int j = 0; j < answers[i].size(); j++){
                    if(first){
                        first = false;
                        std::cout << answers[i][j] << "";
                    }else{
                        std::cout << '+' << answers[i][j] << "";
                    }
                }
                std::cout << std::endl;
            }
        }
    }
}