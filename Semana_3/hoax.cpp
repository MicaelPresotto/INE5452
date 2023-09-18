#include <iostream>
#include <set>

int main(void){
    while(1){
        std::multiset<int> myMultiset = {};
        int n;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        unsigned long long soma = 0;
        for(int i = 0; i < n; i++){
            int a;
            std::cin >> a;
            for(int j = 0; j < a; j++){
                int b;
                std::cin >> b;
                myMultiset.insert(b);
            }
            int maximum = *myMultiset.rbegin();
            auto it = myMultiset.find(maximum);
            myMultiset.erase(it);
            int minimum = *myMultiset.begin();
            auto it2 = myMultiset.find(minimum);
            myMultiset.erase(it2);
            int diff = maximum - minimum;
            soma += diff;
        }
        std::cout << soma << std::endl;
    }
}