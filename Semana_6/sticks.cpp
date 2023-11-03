// palitos coloridos eh jogado em uma pilha
// emanharada na mesa
// os jogadores tentam pegar um unico palito de cada
// vez sem mover nenhum dos outros gravetos
// eh dificil pegar um palito se tiver outro pedaco
// de madeira em cima dele
// os jogadores tentam pegar os gravetos em uma ordem
// de modo que eles nunca precisam escolher um graveto
// que esteja embaixo de outro

// input
// o input consiste em varios casos testes
// a primeira linha- de caso de teste contem
// 2 inteiros n e m
// n eh o numero de palitos
// e m eh o proximo numero de linhas
// os gravetos estao enumerados de 1 a n
// cada uma das proximas m linhas contem 2 inteiros
// a e b, indicando que o palito b esta embaixo do palito a
// a entrada termina com n = m = 0

// output
// imprimir uma lista de gravetos em ordem que eles
// devem ser pegos para que nenhum palito seja pego
// antes de um palito que esteja embaixo dele
// se nao for possivel, imprimir a mensagem
// "IMPOSSIBLE"

#include <iostream>
#include <vector>

enum class State { NOT_VISITED, TEMPORARY_VISITED, PERMANENTLY_VISITED };

bool hasCycleDFS(std::vector<std::vector<int>>& graph, std::vector<State>& visited, int u) {
    visited[u] = State::TEMPORARY_VISITED;

    for (int v : graph[u]) {
        if (visited[v] == State::TEMPORARY_VISITED) {
            // Encontrou um vértice já visitado temporariamente, indicando um ciclo.
            return true;
        } else if (visited[v] == State::NOT_VISITED) {
            if (hasCycleDFS(graph, visited, v)) {
                return true;
            }
        }
    }

    visited[u] = State::PERMANENTLY_VISITED;
    return false;
}

bool hasCycle(std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<State> visited(n, State::NOT_VISITED);

    for (int i = 0; i < n; i++) {
        if (visited[i] == State::NOT_VISITED) {
            if (hasCycleDFS(graph, visited, i)) {
                return true;
            }
        }
    }

    return false;
}


void DFS_Visit_OT(std::vector<std::vector<int>>& adjs, int u, std::vector<bool>& visited, std::vector<int>& ordem){
    visited[u] = true;
    for(auto &v : adjs[u]){
        if(!visited[v]){
            DFS_Visit_OT(adjs, v, visited, ordem);
        }
    }
    ordem.push_back(u);
}

std::vector<int> dfs(std::vector<std::vector<int>>& adjs, std::vector<bool>& visited){
    std::vector<int> ordem;
    for(int i = 0; i < adjs.size(); i++){
        if(!visited[i]){
            DFS_Visit_OT(adjs, i, visited, ordem);
        }
    }
    return ordem;
}

int main(void){
    for(;;){
        int n, m; std::cin >> n >> m;
        if(n == 0 && m == 0) break;
        std::vector<std::vector<int>> adjs(n, std::vector<int>());
        std::vector<bool> visited(n, false);
        for(int i = 0; i < m; i++){
            int a, b; std::cin >> a >> b;
            adjs[a-1].push_back(b-1);
        }
        if(hasCycle(adjs)){
            std::cout << "IMPOSSIBLE" << std::endl;
            continue;
        }
        std::vector<int> ord = dfs(adjs, visited);
        for(int i = ord.size()-1; i >= 0; i--){
            std::cout << ord[i]+1 << std::endl;
        }
    }

}