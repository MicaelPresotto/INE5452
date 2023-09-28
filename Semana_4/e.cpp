#include <iostream>
#include <vector>
#include <bitset>

int somarVetor(const std::vector<int>& vetor) {
    int soma = 0;
    for (int i = 0; i < vetor.size(); i++) {
        soma += vetor[i];
    }
    return soma;
}


std::vector<int> solve(std::vector<std::vector<int>> matrix, int resposta){
    std::vector<int> best_solution(20);
    for(int i = 0; i < matrix.size(); i++){
        int soma = 0;
        std::vector <int> answers;
        for(int j = 0; j < matrix[i].size(); j++){
            soma += matrix[i][j];
            answers.push_back(matrix[i][j]);
        }
        if(soma <= resposta){
            if(somarVetor(answers) >= somarVetor(best_solution)){
                best_solution = answers;
            }
        }
    }
    return best_solution;
}

int main(void){
    int n, tracks;
    while(std::cin >> n >> tracks){
        std::vector<int> tracks_length(tracks);
        std::vector<std::vector<int>> matrix;
        std::bitset<20> conjunto;
        for(int i = 0; i < tracks; i++){
            std::cin >> tracks_length[i];
        }
        for(int i = 0; i < (1 << tracks); i++){
            conjunto = i;
            std::vector<int> line;
            for(int j = 0; j < tracks; j++){
                if(conjunto[j]){
                    line.push_back(tracks_length[j]);
                }
            }
            matrix.push_back(line);
        }
        std::vector<int> answer = solve(matrix, n);
        for(int i = 0; i < answer.size(); i++){
            std::cout << answer[i] << " ";
        }
        std::cout << "sum:" << somarVetor(answer) << std::endl;
    }
}