// chess boarde de 8x8 e tem 8 queens colocadas randomicamente no tabuleiro
// cada uma das 8 rainhas estaos em colunas diferentes
// oq significa q elas 2 rainhas n se atacam uma a outra verticalmente
// mas se atacam horizontalmente e diagonalmente
// eu preciso mover as rainhas de tal forma que elas nao se ataquem de 
// nenhuma forma
// sou permitido a mover elas verticalmente e por isso
// posso apenas mover as linhas de cada rainha e nao as colunas
// um movimento consiste em mover uma rainha para
// (R1,C ) para (R2,C) onde r1 != r2
// preciso achar o menor numero de movimentos possiveis

//input
// terao multiplos casos testes onde cada linha consiste de 8 inteiros
// todos esses inteiros estarao entre 1 e 8
// o i-esimo inteiro indica posicao da lihnha da rainhna i-esima coluna


//output
// para cada caso teste, imprima o caso teste e o numero minimo de movimentos

// testar para cada rainha todas as posicoes que ela pode assumir
#include <iostream>
#include <vector>


#include <vector>


// ainda nao funciona, estou pensando formas de resolver


// Função para verificar se uma rainha não se ataca com as outras rainhas
bool safe(const std::vector<std::vector<int>>& matrix, int row1, int col1) {
    int n = matrix.size(); // Tamanho da matriz (assumindo que seja uma matriz quadrada)

    // Verificar se a rainha não se ataca horizontalmente na mesma linha
    for (int col = 0; col < n; col++) {
        if (col != col1 && matrix[row1][col] == 1) {
            return false;
        }
    }

    // Verificar se a rainha não se ataca diagonalmente
    for (int i = 1; i < n; i++) {
        // Diagonal superior esquerda
        if (row1 - i >= 0 && col1 - i >= 0 && matrix[row1 - i][col1 - i] == 1) {
            return false;
        }

        // Diagonal superior direita
        if (row1 - i >= 0 && col1 + i < n && matrix[row1 - i][col1 + i] == 1) {
            return false;
        }

        // Diagonal inferior esquerda
        if (row1 + i < n && col1 - i >= 0 && matrix[row1 + i][col1 - i] == 1) {
            return false;
        }

        // Diagonal inferior direita
        if (row1 + i < n && col1 + i < n && matrix[row1 + i][col1 + i] == 1) {
            return false;
        }
    }

    // Se não se atacar horizontalmente ou diagonalmente, é seguro
    return true;
}


bool solve(std::vector<std::vector<int>> matrix){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (matrix[i][j] == 1){
                //printando a linha a coluna e a diagonal
                if(!safe(matrix, i, j)){
                    matrix[i][j] = 0;
                    matrix[i+1][j] = 1;
                }
            }
        }
    }
}

int main(void){
    for(;;){
        std::vector<std::vector<int>> matrix(8, std::vector<int>(8, 0));
        for(int i = 0; i < 8; i++){
            int k;std::cin >> k;
            matrix[k-1][i] = 1;

        }
        if(std::cin.eof()) break;
        if(safe(matrix, 0, 0)){
            std::cout << "ok" << std::endl;
        }
    }
    return 0;
}