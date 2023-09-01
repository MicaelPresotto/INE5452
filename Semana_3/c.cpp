#include <iostream>
#include <vector>
#include <queue>

int main() {
    for(;;){
        std::vector<int> numeros;
        std::priority_queue<int> pq;
        int n;

        std::cin >> n;
        if(n==0) break;

        for (int i = 0; i < n; ++i) {
            int num;
            std::cin >> num;
            numeros.push_back(num);
            pq.push(num*(-1));
        }
        int x = 0;
        while(pq.size() > 1){
            int v1 = pq.top();
            pq.pop();
            int v2 = pq.top();
            pq.pop();
            int sum = v1+v2;
            pq.push(sum);
            x += sum;
        }
        printf("%d\n", x*(-1));
    }
    return 0;
}