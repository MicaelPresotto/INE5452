#include <iostream>
#include <bitset>
#include <vector>

std::string solve(std::vector<std::vector<int>> matrix, int resposta){
    for(int i = 0; i < matrix.size(); i++){
        int soma = 0;
        for(int j = 0; j < matrix[i].size(); j++){
            soma += matrix[i][j];
        }
        if(soma == resposta){
            return "YES";
        }
    }
    return "NO";
}

int main(void) {
    int t;
    std::cin >> t;
    
    for(int k = 0; k < t; k++) {
        int n;
        std::cin >> n;
        
        int p;
        std::cin >> p;
        
        const int tamanho_conjunto = 20;
        std::bitset<tamanho_conjunto> conjunto;
        std::vector<int> x(p);
        std::vector<std::vector<int>> matrix;
        
        for (int i = 0; i < p; i++) {
            std::cin >> x[i];
        }
        
        for (int i = 0; i < (1 << p); i++) {
            conjunto = i;
            std::vector<int> line;
            for (int j = 0; j < p; j++) {
                if (conjunto[j]) {
                    line.push_back(x[j]);
                }
            }
            matrix.push_back(line);
        }
        std::cout << solve(matrix, n) << std::endl;

    }
    
    return 0;
}
