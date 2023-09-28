// 3 diferentes inteiros x y e z que satisfazem a seguinte relacao
// x + y + z = A
//x*y*z = B
// x**2 + y**2 + z**2 = C
// tenho que fazer um programa que leia A B e C e mostre x y e z

// caso houver mais de uma solution mostrar a equacao com menor valor de x
// se empatar menor valor de y e etc
// caso nao tiver imprimir no solution
#include <iostream>
#include <vector>

std::vector<std::vector<int>> solve(int a, int b, int c){
    std::vector<std::vector<int>> answers;
    for(int x = -101; x < 101; x++){
        for(int y = -101; y < 101; y++){
            for(int z = -101; z < 101; z++){
                if(x+y+z == a && x*y*z == b && x*x + y*y + z*z == c && x != y && x != z && y != z){
                    answers.push_back(std::vector<int> {x,y,z});
                }
            }
        }
    }
    return answers;
}

int main(void){
    int n; std::cin >> n;
    for(int _ = 0; _ < n; _++){
        int a,b,c; std::cin >> a >> b >> c;
        int x,y,z;
        std::vector<std::vector<int>> answer = solve(a,b,c);
        if(answer.empty()) {std::cout << "No solution." << std::endl;
        }else if(answer.size() > 1){
            int min_x, min_y, min_z;
            min_x = answer[0][0];
            min_y = answer[0][1];
            min_z = answer[0][2];
            for(int i = 1; i < answer.size(); i++){
                if(answer[i][0] < min_x){
                    min_x = answer[i][0];
                    min_y = answer[i][1];
                    min_z = answer[i][2];
                }else if(answer[i][0] == min_x){
                    if(answer[i][1] < min_y){
                        min_x = answer[i][0];
                        min_y = answer[i][1];
                        min_z = answer[i][2];
                    }else if(answer[i][1] == min_y){
                        if(answer[i][2] < min_z){
                            min_x = answer[i][0];
                            min_y = answer[i][1];
                            min_z = answer[i][2];
                        }
                    }
                }
            }
            std::cout << min_x << " " << min_y << " " << min_z << std::endl;
        }else{
            std::cout << answer[0][0] << " " << answer[0][1] << " " << answer[0][2] << std::endl;
        }
    }
}