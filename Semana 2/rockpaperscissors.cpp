#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

int main() {
    bool first = true;
    while (1) {
        int p, k;
        std::cin >> p;
        if (p == 0) {
            break; // Exit the loop if p is 0
        }
        if(first) first = false;
        else std::cout << '\n';
        
        std::cin >> k;
        
        std::vector<int> wins(p, 0);
        std::vector<int> loses(p, 0);
        int n = k * p * (p - 1) / 2;

        for (int i = 0; i < n; ++i) {
            int p1, p2;
            std::string m1, m2;
            std::cin >> p1 >> m1 >> p2 >> m2;
            if (m1 == m2) {
                continue;
            } else if ((m1 == "rock" && m2 == "scissors") || (m1 == "paper" && m2 == "rock") || (m1 == "scissors" && m2 == "paper")) {
                wins[p1-1]++;
                loses[p2-1]++;
            } else {
                wins[p2-1]++;
                loses[p1-1]++;
            }
        }
        
        for (int i = 0; i < wins.size(); i++){
            if (wins[i] + loses[i] == 0){
                std::cout << "-\n";
            } else {
                std::cout << std::fixed << std::setprecision(3) << static_cast<double>(wins[i]) / (wins[i] + loses[i]) << '\n';


            }
        }
    }

    return 0;
}
