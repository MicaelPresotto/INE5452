#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    std::vector<int> myVec;
    int x;
    while(scanf("%d", &x) != EOF){
        myVec.push_back(x);
        int size = myVec.size();
        std::nth_element(myVec.begin(), myVec.begin()+(size/2), myVec.end()); //nth_element coloca o elemento que deveria estar naquela posicao caso a lista fosse ordenada
        int v = myVec[size/2];
        if(size%2==0){
            std::nth_element(myVec.begin(), myVec.begin()+((size/2)-1), myVec.end());
            int x = myVec[(size/2)-1];
            printf("%d\n", (v+x)/2);
        }
        else printf("%d\n", myVec[size/2]);
    }
    return 0;
}