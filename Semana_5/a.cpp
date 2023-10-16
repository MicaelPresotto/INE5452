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
#include <map>
#include <vector>
#include <algorithm>

std::pair<std::string, int> solve(std::map<char, std::vector<int>>& position, std::string& ss){
    int current = 0;
    for(int j = 0; j < ss.size(); j++){
        int index = ss[j];
        auto it = std::upper_bound(position[index].begin(), position[index].end(), current);
        if(it == position[index].end()){
            return std::make_pair("Not matched", current);
        }
        current = *it;
    }
    return std::make_pair("Matched", current);
}

int main(void){
    std::string s; std::cin >> s;
    std::map<char, std::vector<int>> mp;
    int q; std::cin >> q;
    for(int j = 0; j < s.size(); j++){
        mp[s[j]].push_back(j);
    }
    while(q--){
        std::string ss; std::cin >> ss;
        std::pair<std::string, int> ans = solve(mp, ss);
        if(ans.first == "Matched"){
            int a1 = mp[ss[0]][0];
            int a2 = ans.second;
            std::cout << ans.first << " " << a1 << " " << a2 << std::endl;
        }else{
            std::cout << ans.first << std::endl;
        }
    }
}