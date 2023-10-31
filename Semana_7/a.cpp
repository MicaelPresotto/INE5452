// World Transformation
// Pegando uma palavra de inicio e ir alterando
// caractere a caractere para fazer uma nova palavra
// por exemplo spice consegue virar stock na seguinte ordem
// spice -> slice -> slick -> stick -> stock
// dado um dict de words, e uma palavra de inicio e fim
// descobrir o menor numero de transformacoes necessarias

// input
// primeira linha eh um inteiro N indicando o numero de conjunto
// de testes para o programa
// cada conjunto de teste tera 2 secoes
// a primeira secao sera um dicionaro de palavras disponveis com
// uma palavra por linha, que terminara com *
// depois do dicionario terao pares de palavras de inicio e fim

// output
// para cada par de palavras de inicio e fim, imprimir o menor
// numero de transformacoes necessarias para transformar a palavra

// cada word eh um vertice
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

std::vector<bool> visited;
std::vector<int> d, pai;

void bfs(int s, int t, std::vector<std::vector<int>>& adj){
    std::queue<int> q;
    visited[s] = true;
    d[s] = 0;
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 0; v < adj.size(); v++){
            if(!visited[v] && adj[u][v] == 1){
                visited[v] = true;
                d[v] = d[u] + 1;
                pai[v] = u;
                if(v == t) return;
                q.push(v);
            }
        }
    }
}

bool cont_diff_letters(std::string a, std::string b){
    int cont = 0;
    if(a.size() != b.size()) return false;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) cont++;
    }
    if (cont == 1) return true;
    return false;
}

int main(void){
    int n; std::cin >> n;
    bool first = true;
    while(n--){
        visited.clear();
        d.clear();
        pai.clear();
        if(first) first = false;
        else std::cout << std::endl;
        std::string word;
        std::map<std::string, int> dict;
        int cont = 0;
        while(std::cin >> word){
            if(word == "*") break;
            dict[word] = cont;
            cont++;
        }
        visited.resize(cont, false);
        d.resize(cont, 0);
        pai.resize(cont, -1);
        std::vector<std::vector<int>> adj(cont, std::vector<int>(cont, 0));
        for(auto x : dict){
            for(auto y : dict){
                if(cont_diff_letters(x.first, y.first)){
                    adj[x.second][y.second] = 1;
                }
            }
        }
        std::string start, end;
        std::string line;
        std::getline(std::cin, line);
        while(std::getline(std::cin, line) && line != ""){
            start = line.substr(0, line.find(" "));
            end = line.substr(line.find(" ") + 1, line.size());
            bfs(dict[start], dict[end], adj);
            std::cout << start << " " << end << " " << d[dict[end]] << std::endl;
            visited.clear();
            d.clear();
            pai.clear();
            visited.resize(cont, false);
            d.resize(cont, 0);
            pai.resize(cont, -1);
        }
        
    }
}