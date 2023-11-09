#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
// fazer uma bfs para cada ponto de partida
// ir somando a cada vez q eu encontrar um water(nao conta o ponto em que foi dado)
// lembrar que diagonal tambem eh adjacente, entao tem q fazer esses casos
// se for 1, entao nao conta, se for 2, entao ja foi visitado
// se for 0, entao conta e marca como visitado

int flood_fill(std::vector<std::vector<int>> grid, int i, int j){
    int n = grid.size();
    int m = grid[0].size();
    int cont = 0;
    if (grid[i][j] == 1) return 0;
    std::queue<std::pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(grid[x][y] == 0) cont++;
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 2 || grid[x][y] == 1) continue;
        grid[x][y] = 2;
        if(x+1 < n)
        q.push({x+1, y});
        if(x-1 >= 0)
        q.push({x-1, y});
        if(y+1 < m)
        q.push({x, y+1});
        if(y-1 >= 0)
        q.push({x, y-1});
        if(x+1 < n && y+1 < m)
        q.push({x+1, y+1});
        if(x+1 < n && y-1 >= 0)
        q.push({x+1, y-1});
        if(x-1 >= 0 && y+1 < m)
        q.push({x-1, y+1});
        if(x-1 >= 0 && y-1 >= 0)
        q.push({x-1, y-1});
    }
    return cont;
}

int main() {
    int n;
    std::cin >> n;
    std::string teste;
    std::getline(std::cin, teste);
    std::cin.ignore();
    bool first = true;
    while(n--) {
        if(first) first = false;
        else std::cout << std::endl;
        std::vector<std::vector<char>> mapa;
        std::string first_line;
        for(;;){
            std::getline(std::cin, first_line);
            if (first_line[0] != 'W' && first_line[0] != 'L') break;
            std::vector<char> linha;
            for(int i = 0; i < first_line.size(); i++){
                if (first_line[i] == 'W' || first_line[i] == 'L')
                    linha.push_back(first_line[i]);
            }
            mapa.push_back(linha);
        }

        // copiando mapa para uma nova matriz, para poder fazer flood fill
        // caso for 'W' entao eh 0, caso for 'L' entao eh 1
        std::vector<std::vector<int>> new_mapa(mapa.size(), std::vector<int>(mapa[0].size()));
        for(int i = 0; i < mapa.size(); i++){
            for(int j = 0; j < mapa[0].size(); j++){
                if(mapa[i][j] == 'W') new_mapa[i][j] = 0;
                else if(mapa[i][j] == 'L') new_mapa[i][j] = 1;
            }
        }
        do{
            std::stringstream ss(first_line);
            int i, j;
            ss >> i >> j;
            i--;j--;
            std::cout << flood_fill(new_mapa, i, j) << std::endl;
            if(std::cin.eof()) break;
            std::getline(std::cin, first_line);
        }while (first_line != "");

        
    }
}
