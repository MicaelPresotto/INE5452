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
bool safe(const std::vector<std::vector<int>>& matrix, int row, int col) {
    int n = matrix.size(); // Tamanho da matriz (assumindo que seja uma matriz quadrada)

    // Verificando se há alguma rainha na mesma linha ou coluna
    for (int i = 0; i < n; i++) {
        if (matrix[row][i] == 1 || matrix[i][col] == 1) {
            return false;
        }
    }
    // Diagonal inferior direita
    int i,j;
    i = row+1, j = col +1;
    while(i < n && j < n) {
        if (matrix[i][j] == 1) {
            return false;
        }
        i++;
        j++;

    }
    // Diagonal inferior esquerda
    i = row+1, j = col -1;
    while(i < n && j >= 0) {
        if (matrix[i][j] == 1) {
            return false;
        }
        i++;
        j--;
    }

    // Diagonal superior direita
    i = row-1, j = col +1;
    while(i >= 0 && j < n) {
        if (matrix[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }

    // Diagonal superior esquerda
    i = row-1, j = col -1;
    while(i >= 0 && j >= 0) {
        if (matrix[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }
    return true;
}

bool all_safe(const std::vector<std::vector<int>>& matrix){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(matrix[i][j] == 1){
                if(!safe(matrix, i, j)){
                    return false;
                }
            }
        }
    }
    return true;
}

int solve(std::vector<std::vector<int>> &matrix,std::vector<std::pair<int, int>> &queens, std::vector<bool> &used, int col){
    int n = matrix.size();
    if(col == 8){
        if (all_safe(matrix)){
            return 0;
        }
        return 2e9;
    }
    int min = 2e9;
    auto[qi, qj] = queens[col];
    for(int row = 0; row < 8; row++){
        if(used[row]) continue;
        if(!safe(matrix, row, qj)) continue;
        used[row] = true;
        queens[col].first = row;
        matrix[row][qj] = 1;
        int solved = solve(matrix, queens, used, col+1);
        if (row != qi) solved++;
        min = std::min(min, solved);
        matrix[row][qj] = 0;
        queens[col].first = qi;
        used[row] = false;
    }
    return min;
}

int main(void){
    int caso = 1;
    for(;;){
        std::vector<std::vector<int>> matrix(8, std::vector<int>(8, 0));
        std::vector<std::pair<int, int>> queens;
        std::vector<bool> used;
        for(int i = 0; i < 8; i++){
            int k;std::cin >> k;
            queens.push_back(std::make_pair(k-1, i));
            used.push_back(false);

        }
        if(std::cin.eof()) break;
        int min = solve(matrix, queens, used, 0);
        std::cout<< min << std::endl;
        }
}
