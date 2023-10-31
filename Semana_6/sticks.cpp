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
// a primeira linha de caso de teste contem
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

void dfs(std::vector<std::vector<int>> &adjs, int u, std::vector<int>&ordem, std::vector<bool> &visited) {
    visited[u] = true;
    for (int v = 0; v < adjs.size(); v++) {
        if (adjs[u][v] == 1 && !visited[v]) {
            dfs(adjs, v, ordem, visited);
        }
    }
    ordem.push_back(u);
}

std::vector<int> ordenacao(std::vector<std::vector<int>> &adjs){
    std::vector<int> ordem;
    std::vector<bool> visited(adjs.size(), false);
    for(int i = 0; i < adjs.size(); i++){
        if(!visited[i]){
            dfs(adjs, i, ordem, visited);
        }
    }
    return ordem;
}

int main(void){
    for(;;){
        int n, m; std::cin >> n >> m;
        if(n == 0 && m == 0) break;
        std::vector<std::vector<int>> adjs(n, std::vector<int>(n, 0));
        std::vector<bool> visited(n, false);
        for(int i = 0; i < m; i++){
            int a, b; std::cin >> a >> b;
            adjs[a-1][b-1] = 1;
        }
        std::vector<int> ordem = ordenacao(adjs);
        for(int i = ordem.size()-1; i >= 0 ; i--){
            std::cout << ordem[i]+1 << std::endl;
        }
        
    }

}