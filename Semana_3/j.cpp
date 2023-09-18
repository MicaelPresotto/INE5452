// fizeram uma exibicao de selos e nao sabem como dividr a grana
// Eles decidiram dividir o seu dinheiro de acordo com esta regra: “A percentagem do rendimento total que
// O i-ésimo amigo receberá é igual à parte do tipo de seu selo exclusivo.”
// O tipo de selo é denominado único se e somente se este tipo de selo pertencer apenas a uma pessoa
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include<iomanip>

int main(void){
    int k;
    std::cin >> k;
    for(int i = 0; i < k; i++){
        int n;
        std::map<int, std::set<int>> mp;
        std::cin >> n;
        std::vector<int> friends(n);
        for(int j = 0; j < n; j++){
            int m;
            std::cin >> m;
            for(int k = 0; k < m; k++){
                int stamps;
                std::cin >> stamps;
                mp[stamps].insert(j);
            }
        }
        int unique = 0;
        for (auto&[label, st] : mp) {
            if (st.size() == 1) {
                friends[*st.begin()]++;
                unique++;
            }
        }
        std::cout << "Case " << i+1 << ": ";
        for(int j = 0; j < friends.size(); j++){
            double percent = (double) friends[j]/unique * 100;
            std::cout << std::fixed << std::setprecision(6) << percent << "%"; 
            if (j != friends.size() - 1)
                std::cout << " ";
            else
                std::cout << '\n';
        }
    }
}

