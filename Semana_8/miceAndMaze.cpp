// ratos sao treinados para escapar do labirinto

// input
// o input comeca com um inteiro indicando o numero de casos
// as primeiras 3 linhas do input contem N, o numero de celulas no labirinto
// E o numero de celulas de saida
// e o valor de comeco T para a contagem em unidades de tempo
// a quarta linha contem um numero M de conexoes no labirinto
// uma conexao eh dada por vertice vertice peso
// cada conexao eh um arco
// tera 1 rato por vertice, tenho que descobrir quantos ratos escapam do labirinto em ate T unidades de tempo
// ou seja, rodar um dijsktra pelo grafo invertido(pois tenho 1 saida e varias entradas) e verificar quantos ratos escapam


//output
// para cada caso de teste, imprima uma linha contendo o numero de ratos que escaparam do labirinto em ate T unidades de tempo


#include <iostream>
#include <vector>
#include <map>
using namespace std;


bool is_there_false_in_visited(vector<bool>& visited) {
    for (const auto& v : visited) {
        if (!v) return true;
    }
    return false;
}

int minimum_distance(vector<int> dist, vector<bool> visited) {
    int min = 1e9;
    int min_index = -1;
    for (int i = 0; i < dist.size(); i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

vector<int> dijkstra(vector<std::vector<int>>& adj_list, map<std::pair<int, int>, int>& edges, int start) {
    vector<int> dist(adj_list.size(), 1e9);
    dist[start] = 0;
    vector<bool> visited(adj_list.size(), false);
    while (is_there_false_in_visited(visited)) {
        int u = minimum_distance(dist, visited);
        visited[u] = true;
        for (const auto& v : adj_list[u]) {
            if (!visited[v] && dist[u] != 1e9 && dist[u] + edges[std::make_pair(u, v)] < dist[v]) {
                dist[v] = dist[u] + edges[std::make_pair(u, v)];
            }
        }
    }
    return dist;
}

int main(void){
    int numb_of_cases; cin >> numb_of_cases;
    bool first = true;
    while(numb_of_cases--){
        if(!first) cout << endl;
        else first = false;
        int numb_of_cells, exit, timer; cin >> numb_of_cells >> exit >> timer;
        int numb_of_connections; cin >> numb_of_connections;
        map<pair<int,int>, int> edges;
        vector<vector<int>> adj_list(numb_of_cells+1);
        while(numb_of_connections--){
            int u,v,w; cin >> u >> v >> w;
            // fazendo grafo invertido
            edges[make_pair(v,u)] = w;
            adj_list[v].push_back(u);
        }
        vector<bool> visited(numb_of_cells+1, false);
        int numb_of_mice = 0;
        vector<int> result_dijkstra = dijkstra(adj_list, edges, exit);
        for(auto& v : result_dijkstra){
            if(v <= timer) numb_of_mice++;
        }
        cout << numb_of_mice << endl;

    }
}