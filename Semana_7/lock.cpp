// tipo especial de cadeado
// ferulock
// sempre mostra valores de 4 digitos tem um codigo especifico para dar unlock
// o cadeado eh aberto quando o codigo eh digitado
// o codigo para abrir pode aparece rapido com ajudas de uns botoes
// que tem um numero associado a eles
// quando um botao eh pressionado o numero associado a eles eh adicionado
// o cadeado sempre usa pelo menos 4 significantes adicoes

//input
// terao while true casos testes
// para cada caso teste tera 3 numeros L U R 
// L representa o atual codigo do cadeado
// U representa o codigo que abre o cadeado
// R representa o numero de botoes
// tera R numeros in uma linha indicado o valor dos botoes

// output
// para cada caso teste
// imprimir o numero numero de botoes pressionados para abrir o cadeado
// caso nao seja possivel imprimir Permantly Locked


#include <iostream>
#include <vector>
#include <queue>


std::vector<bool> visited;
std::vector<int> d;

int bfs(int s, int t, std::vector<std::vector<int>>& adj){
    std::queue<int> q;
    visited[s] = true;
    d[s] = 0;
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            if(!visited[v]){
                visited[v] = true;
                d[v] = d[u] + 1;
                if(v == t) return d[v];
                q.push(v);
            }
        }
    }
    return -1;
}

int main(void){
    int test_case = 0;
    for(;;){
        d.clear();
        visited.clear();
        int l, u , r; std::cin >> l >> u >> r;
        if(l == 0 && u == 0 && r == 0) break;
        std::vector<int> buttons(r);
        std::vector<std::vector<int>> adj(10000);
        for(int i = 0; i < r; i++){
            std::cin >> buttons[i];
        }
        for(int i = 0; i <= 9999; ++i){
            visited.push_back(false);
            d.push_back(0);
            for(int j : buttons){
                adj[i].push_back((i + j) % 10000);
            }
        }
        int ans = bfs(l, u, adj);
        if(ans == -1) std::cout << "Case " << ++test_case << ": " << "Permanently Locked" << std::endl;
        else std::cout << "Case " << ++test_case << ": " << ans << std::endl;
    }
}