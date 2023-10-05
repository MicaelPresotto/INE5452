#include <iostream>
#include <algorithm>
#include <vector>
#include <array>


// satisfazer as constraints
// se c for positivo entao a e b devem estar ate c posicoes a partes
// se c for negativo entao a e b devm estar pelo menos -c posicoes a partes

bool solve(std::vector<std::array<int, 3>> constraints, std::vector<int> seats){
    for(auto arr : constraints){
        int left = -1;
        int ca = arr[0];
        int cb = arr[1];
        int distance = arr[2];
        for(int i = 0; i < seats.size(); i++){
            // pego o primeiro elemento a esquerda que aparece
            if(seats[i] == ca || seats[i] == cb){
                if (left == -1){
                    // so seto quando pra quando eu achar um elemento mais a esquerda
                    left = i;
                    continue;
                }
                if(distance > 0){
                    // se a dist for positiva entao eles tem de estar 
                    // no maximo c posicoes, se nao, nao satisfaz
                    if(i - left > distance) return false;
                    break;
                }
                if (distance < 0){
                    // se dist for negativa entao eles tem de estar pelo menos
                    // c posicoes a parte, ou seja tem de ser c ou mais
                    if( i - left < abs(distance)) return false;
                    break;
                }
            }
        }
    }
    return true;
}

int main(void){
    for(;;){
        int n, m; std::cin >> n >> m;
        if (n == 0 && m == 0) break;
        std::vector<int> seats(n);
        std::vector<std::array<int, 3>> constraints;
        for(int i = 0; i < n; i++){
            seats[i] = i;
        }
        int cont = 0;
        if(m==0){
            do {
                cont++;
            }while (std::next_permutation(seats.begin(), seats.end()));
        } else{
            for(int i = 0; i < m; i++){
                int a, b, c; std::cin >> a >> b >> c;
                std::array<int, 3> arr = {a, b, c};
                constraints.push_back(arr);
            }
            do{
                if (solve(constraints, seats)) cont++;
            }while (std::next_permutation(seats.begin(), seats.end()));

            
        }
        std::cout << cont << std::endl;
    }
}