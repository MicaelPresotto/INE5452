#include <iostream>
#include <algorithm>
#include <vector>
int main(void){
    for(;;){
        int n, m; std::cin >> n >> m;
        if (n == 0 && m == 0) break;
        std::vector<int> seats(n);
        for(int i = 0; i < n; i++){
            seats[i] = i;
        }
        int cont = 0;
        if(m==0){
            do {
                cont++;
            }while (std::next_permutation(seats.begin(), seats.end()));
        }
        for(int i = 0; i < m; i++){
            int a,b,c; std::cin >> a >> b >> c;
            do{
                if(c==0){
                    if(abs(seats[b] - seats[a]) <= c) cont++;
                }else{
                    if(abs(seats[b] - seats[a]) >= abs(c)) cont++;
                } 
                }while(std::next_permutation(seats.begin(), seats.end()));
        }
        std::cout << cont << '\n';
    }
}