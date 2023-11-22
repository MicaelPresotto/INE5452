// comecar implementando bellman-ford sobre o grafo dado
// irei fazer um map de cada aresta com seu respsctivo peso
// se acaso o grafo conter um ciclo negativo, retornar possible
// se nao, retornar impossible

#include <iostream>
#include <map>
#include <vector>

int main(void){
    int n; std::cin >> n;
    while(n--){
        int v,e; std::cin >> v >> e;
        std::map<std::pair<int, int>, int> distances;
        for(int i = 0; i < e; i++){
            int a,b,c; std::cin >> a >> b >> c;
            distances[{a,b}] = c;
        }

        // bellman-ford
        std::vector<int> dist(v, 100000000);
        
        dist[0] = 0;
        for(int i = 0; i < v-1; i++){
            for(auto it = distances.begin(); it != distances.end(); it++){
                int u = it->first.first;
                int v = it->first.second;
                int w = it->second;
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        bool possible = false;
        for(auto it = distances.begin(); it != distances.end(); it++){
            int u = it->first.first;
            int v = it->first.second;
            int w = it->second;
            if(dist[u] + w < dist[v]){
                std::cout << "possible" << std::endl;
                possible = true;
                break;
            }
        }
        if(!possible) std::cout << "not possible" << std::endl;
    }
}