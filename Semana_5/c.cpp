//Na Quadradonia todas as propriedades rurais são quadradas, 
// todas têm a mesma área, todas estão perfeitamente planas e todas
// ter os lados alinhados aos eixos Norte-Sul e Oeste-Leste

// a empresa esta interessada em
// alugar terrenos cuja altura eh maior ou igual do que uma
// altitude L
// e menor ou algo do que uma altitude U
// para deixar a colheita mas facil,
// a empresa deve alugar terrenos que formam uma area contigua
// a area deve ser um quadrado

// a compania n decidiu ainda que tipos de uvas irao crescer
// entao tem uma lista de consultas envolvendo intervalos

// preciso escrever um programa que dado a descricao da area
// retangular de interesse da monhtanha e a lista de consultas contendo
// os intervalos de altura, determinar para cada consulta
// o tamanho maximo do quadrado que pode ser formado

//input
// o input tem varios casos testes
// a primeira linha de cada caso teste tem 2 numeros N e M
// indicando o numero de propriedades north to south e west to east direction
// da regiao de interesse
// nas proximas N linhas contem M inteniros H indicando a altura das propriedades
// de interesse
// as proximas linhas contem um inteiro Q indicando o numero de consultas
// sa proximas Q linhas contem uma consulta que contem dois inteiros L e U
// indicando o intervalo de alturas
// a altura das propriedades para alugar tem de ser maior ou igual a L e menor ou igual a U

//output
// para cada caso teste o programa deve printar q+1 linhas
// cada q linha deve conter um inteiro indicando o tamanho maximo do quadrado
// a ultima linha a ser printada para cada caso teste eh -

#include <iostream>
#include <vector>
#include <algorithm>
int main(void){
    for(;;){
        int max = 0;
        int n,m; std::cin >> n >> m;
        if(n == 0 && m == 0) break;
        std::vector<std::vector<int>> matrix;
        for(int i = 0; i < n; i++){
            std::vector<int> row;
            for(int j = 0; j < m; j++){
                int x; std::cin >> x;
                row.push_back(x);
            }
            matrix.push_back(row);
        }
        int q; std::cin >> q;
        for(int i = 0; i < q; i++){
            int l, u; std::cin >> l >> u;
            for(int j = 0; j < matrix.size(); j++){
                for(int k = 0; j < matrix.size(); k++){
                    if (l >= matrix[j][k]){
                        int cont = 0;
                        int row = j;
                        int col = k;
                        //FIXME: segmentation fault
                        while(matrix[row][col] <= u){
                            max++;
                            row++;
                            cont++;
                        }
                        if(cont > max) max = cont;
                    }
                }
            }
        }
        std::cout << max << std::endl;
    }
}