#include <vector>
#include <iostream>
#include <queue>


// BFS 3D
// fazer um flood fill em um grafo 3D
// basicamente tenho um vector de vector de vector
// 

struct Cell{
    int level,i,j;
};

int flood_fill(std::vector<std::vector<std::vector<char>>>& grid,std::vector<std::vector<std::vector<int>>>& dist, Cell coord_s){
    if (grid[coord_s.level][coord_s.i][coord_s.j] == '#') return 0;
    int x = grid.size();
    int y = grid[0].size();
    int z = grid[0][0].size();
    int cont = 0;
    std::queue<Cell> q;
    q.push(coord_s);
    while(!q.empty()){
        int level = q.front().level;
        int i = q.front().i;
        int j = q.front().j;
        q.pop();
        // checking boundaries
        if (level < 0 || level >= x || i < 0 || i >= y || j < 0 || j >= z || grid[level][i][j] == '#') continue;
        cont++;
        if (grid[level][i][j] == 'E') return dist[level][i][j];
        grid[level][i][j] = '#';
        // adding neighbors
        if(i+1 < y)
        dist[level][i+1][j] = dist[level][i][j] + 1;
        q.push({level, i+1, j});
        if(i-1 >= 0)
        dist[level][i-1][j] = dist[level][i][j] + 1;
        q.push({level, i-1, j});
        if(j+1 < z)
        dist[level][i][j+1] = dist[level][i][j] + 1;
        q.push({level, i, j+1});
        if(j-1 >= 0)
        dist[level][i][j-1] = dist[level][i][j] + 1;
        q.push({level, i, j-1});
        if(level+1 < x)
        dist[level+1][i][j] = dist[level][i][j] + 1;
        q.push({level+1, i, j});
        if(level-1 >= 0)
        dist[level-1][i][j] = dist[level][i][j] + 1;
        q.push({level-1, i, j});
    }
    return 0;
}


int main(void){
    int l,r,c;
    while(std::cin >> l >> r >> c && (l || r || c)){
        std::vector<std::vector<std::vector<char>>> matrix(l, std::vector<std::vector<char>>(r, std::vector<char>(c, '0')));
        std::vector<std::vector<std::vector<int>>> dist(l, std::vector<std::vector<int>>(r, std::vector<int>(c, 0)));
        Cell coord_s = {0,0,0};
        for(int level = 0; level < l; level++){
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    char x; std::cin >> x;
                    if(x == 'S'){
                        coord_s.level = level;
                        coord_s.i = i;
                        coord_s.j = j;
                    }
                    matrix[level][i][j] = x;
                }
            }
        }
        int ans = flood_fill(matrix, dist, coord_s);
        if(ans == 0) std::cout << "Trapped!" << std::endl;
        else std::cout << "Escaped in " << ans << " minute(s)." << std::endl;
    }
}