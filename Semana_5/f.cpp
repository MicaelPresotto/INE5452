// um macaco esta tentando alcancar o topo de um bamboo com oleo
// quando ele escala para cima 3 pes ele cai 2 pes, escalar 3 pes leva 3 segundos, deslizar 2 pes leva 1 segundo
// caso o bamboo tiver 12 pes quanto tempo o macaco precisa para alcancar o topo?
// ao inves de fazer isso o problem setter colocou uma escada no bamboo de tal forma que
// nao eh possivel pular degrau, tem de ir um degrau por vez
// inicialmente define o fator de forca k, k quer dizer que nao consigo pular mais do que k pes
// se eu pular exatamente k pes meu k sera decrementado em 1
// mas se pular menos que k pes o k permanecera o mesmo
// exemplo
// as alturas dos degraus do chao sao 1,6,7,11,13 e meu k = 5
// pulei 1 pe para o primeiro degrau, como pulei menos que 5 meu k permanece 5
// pulei 5 pes para o segundo degrau, como pulei exatamente 5 meu k eh decrementado para 4
// pulei 1 pe para o terceiro degaru, como pulei menos que 4 meu k permanece 4
// pulei 4 pes para o quarto degrau, como pulei exatamente 4 entao meu k eh decrementado para 3
// pulei 3 pes para o quinto degrau, como pulei menos que 3 meu k permanece 3
// Now you are given the heights of the rungs of the ladder from the ground, you have to nd the
// minimum strength factor k, such that I can reach the top rung.

// input
// a primeira linha do input vem um T com test cases
// cada caso teste tem uma linha com um inteiro N denotando o numero de degraus
// a proxima linha contem os N inteiros denotando a altura dos degraus a partir do chao

// output
// cada caso teste printa o caso teste e o k minimo

#include <iostream>
#include <vector>
#include <algorithm>
int main(void){
    int t; std::cin >> t;
    int test_case = 0;
    for(int _ = 0; _ < t; _++){
        test_case++;
        int n; std::cin >> n;
        std::vector<int> v(n);
        for(int i = 0; i < n; i++){
            std::cin >> v[i];
        }
        int maior_diff;
        v.insert(v.begin(), 0);
        for(int i = 0; i < v.size() - 1; i++){
            int diff = v[i + 1] - v[i];
            if(i == 0){
                maior_diff = diff;
            }else{
                maior_diff = std::max(maior_diff, diff);
            }
        }
        int k = maior_diff;
        for(int i = 0; i < v.size() - 1; i++){
            int diff = v[i + 1] - v[i];
            if(diff == maior_diff){
                maior_diff--;
            }else if(diff > maior_diff){
                k++;
                break;
            }
        }
        std::cout << "Case " << test_case << ": " << k << std::endl;
    }
}