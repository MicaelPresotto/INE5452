// Para cada valor a da entrada, 
// busque por um outro valor b a 
// partir da posição de a e que resulte na soma desejada. 
// Pode usar "binary_search" da STL para encontrar o valor b. 
//Minimize a diferença entre a e b.

//demora um ano pra finalizar um livro
// ele ganha dinheiro a cada 2 semanas
// ele comprou 2 livros para ler ate receber mais dinheiro
// ele quer gastar todo o dinheiro, entao a soma dos precos 
// dos livros deve ser igual ao dinheiro que ele tem

//input
// cada caso teste tem o numero de livros livres para compra
// as proximas N linhas tem o preco de cada livro
// e depois disso tem uma linha M com o dinheiro que ele tem

//output
// para cada caso teste, a imagem impressa deve ser que ele deve comprar os livros i e j
// onde i e j sao os precos dos livros cuja soma eh igual a M e i <= j
// sempre eh possivel achar uma solucao
// se tiver multiplas solucoes, imprima a q tem menor diferenca entre i e j


#include <algorithm>
#include <iostream>
#include <vector>

int main(void){
    int n;
    while(scanf("%d ", &n) != EOF){
        std::vector<int> books_prices(n);
        std::vector<std::pair<int,int>> minimize;
        for(int i = 0; i < n; i++){
            std::cin >> books_prices[i];
        }  
        int money; scanf("%d ", &money);
        std::sort(books_prices.begin(), books_prices.end());
        for(int j = 0; j < books_prices.size(); j++){
            int complemento = money - books_prices[j];
            bool is_in_vector = std::binary_search(books_prices.begin()+j+1, books_prices.end(), complemento);
            if(is_in_vector) minimize.push_back(std::make_pair(books_prices[j], complemento));
        }
        int menor_diferenca = 1000000000;
        int first, second;
        for(auto k : minimize){
            int diff = k.second - k.first;
            if(diff < menor_diferenca){
                menor_diferenca = diff;
                first = k.first;
                second = k.second;
            }
        }
        std::cout << "Peter should buy books whose prices are " << first <<  " and " << second << "." << std::endl;
        std::cout << std::endl;
    }
}