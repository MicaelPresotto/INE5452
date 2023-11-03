#include <iostream>
#include <vector>
#include <string>
#include <queue>


int main() {
    int n;
    std::cin >> n;
    
    for (int _ = 0; _ < n; _) {
        std::vector<std::vector<char>> mapa;
        std::string first_line;
        std::cin >> first_line;
        int size = first_line.size();

        // Ler a primeira linha e criar o primeiro vetor
        std::vector<char> linha(size);
        
        for (int i = 0; i < size; i++) {
            linha[i] = first_line[i];
        }
        mapa.push_back(linha);

        // Ler as linhas restantes
        for (int i = 1; i < size; i++) {
            std::vector<char> nova_linha(size);
            for (int j = 0; j < size; j++) {
                char c;
                std::cin >> c;
                nova_linha[j] = c;
            }
            mapa.push_back(nova_linha);
        }

    // fazer uma bfs para cada ponto de partida
    // ir somando a cada vez q eu encontrar um water(nao conta o ponto em que foi dado)
    // lembrar que diagonal tambem eh adjacente, entao tem q fazer esses casos
    }

    return 0;
}
