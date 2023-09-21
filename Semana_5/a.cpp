// a compania iniciou um search program talent
// tem 52 estados
// os canditados dos 52 estados tem uma identidade estadual e um numero serial(unico)
// a identidade dos 52 estados sao os 52 caracteres ASCII  A..Z and a..z
// no max 1 milhao de candidatos concorrem em uma linha de acordo com
// o a ordem crescente do numero serial
// ele escreve uma sequencia de caracteres(apenas alfabeto)
// se os candidatos sao encontrados naquele ordem crescente de 
// numeros seriais, entao o candidato eh aprovado


//input 
// a primeira linha tem uma string S
// a proxima linha tem um inteiro q que indica o numero de queries
// as proximas q linhas tem uma string SS, que sao as string escritas
// pelo Fill Bates

//output
// para cada query tem q imprimir se deu match ou nao
// e a subsequencia e o serial da ultima sequencia da subsequencia

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(void){
    std::string s; std::cin >> s;
    std::vector<std::vector<int>> position;
    int q; std::cin >> q;

    for(int i = 0; i < q; i++){
        std::string ss; std::cin >> ss;
        for(int j = 0; j < s.size(); j++){
            int index = s[j] - 'a';
            position[index].push_back(j);
        }
        bool valid = true;
        
    }
}