#include <iostream>

using namespace std;
int main(){
    int n;
    while(cin >> n && n != 0){
        int curr_val = 0;
        int answer = 0;
        while(n--){
            int val; cin >>val;

            if(curr_val + val < val){
                curr_val = val;
            } else{
                curr_val += val;
            }
            answer = max(answer, curr_val);
        }
        if(answer > 0){
            cout << "The maximum winning streak is " << answer << "." << endl;
        } else{
            cout << "Losing streak." << endl;
        }
    }
}