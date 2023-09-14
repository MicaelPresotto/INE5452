#include <map>
#include <algorithm>
#include <stdio.h>
#include <set>
int main(void){
    for(;;){
        int n;
        scanf("%d ", &n);
        if(n == 0) break;
        int a,b,c,d,e;
        std::map<std::set<int>, int> m;
        for(int i = 0; i < n; i++){
            scanf("%d %d %d %d %d ", &a, &b, &c, &d, &e);
            std::set<int> s;
            s.insert(a);
            s.insert(b);
            s.insert(c);
            s.insert(d);
            s.insert(e);
            m[s]++;
        }
        int max = 0;
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second > max) max = it->second;
        }
        int count = 0;
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second == max) count+=max;
        }
        printf("%d\n", count);
    }
}