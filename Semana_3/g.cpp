// Contest score boards
// primeiro pelo numero de problemas resolvidos
// depois peelo decreasing amounts of penalty time
// penalty time eh o tempo que demorou pra resolver o problema
// se dois ou mais times estiverem com problemas resolvidos e penalty time empatado
// penalty time eh computado pelo numero de minutos que demorou para resolver
// mais 20 minutos de cada submissao incorreta
// para nosso programa
// o input comeca com o numero de casos testes
// a proxima linha eh blank line
// e tambem tem uma linha em branca entre 2 inputs consecutivos
// Input consists of a snapshot of the judging queue, containing entries from some or all of contestants
//1 through 100 solving problems 1 through 9. Each line of input will consist of three numbers and a
//letter in the format
// contestant problem time L
// l pode ser C I R U ou E onde os ultimos tres nao afeta o score

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main(void){
    int n,a,b,c;
    std::string l;
    std::vector<std::vector<int>> v;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> a >> b >> c >> l;
    }
}
// continuar