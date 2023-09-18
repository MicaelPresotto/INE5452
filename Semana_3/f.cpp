// ter certeza de que o calendario esta livre de conflitos pros proximos
// 1 milhao de minutos
// tempo 0 = agora
// no calendario ha 2 tipos de tasks
// 1- one time tasks
// 2 - repeating tasks - repetem para sempre
// one-time tem um start time e um end time
// repeating tem um start time, end time, e um intervalo
//For example, a repeating task with start time 5, end time 8 and repetition interval
//100 would be occurring at time intervals [5..8], [105..108], [205..208]
// as tasks estarao em conflitos se elas estiverem ocorrendo ao mesmo tempo
// ou se elas estiverem ocorrendo em intervalos que se sobrepoe
// por exemplo, uma task que ocorre em [5..8] e outra que ocorre em [7..10]
// "Touching" eh ok, por exemplo [2..5] e [5..6] nao estao em conflito
// n eh o numero de one-time tasks
// m eh o numero de repeating tasks
#include <iostream>
#include <bitset>
#include <string>

std::bitset<1000001> bits;

std::string verify_conflicts(int n, int m, int *start_one, int *end_one, int *start_rep, int *end_rep, int *interval_rep){
    for(int i = 0; i < n; i++){
        for(int j = start_one[i]; j < end_one[i]-1; j++){
            if(bits[j] == 0) bits[j] = 1;
            else return "CONFLICT";
        }
    }
    if (m != 0){
        for(int i = 0; i < m; i++){
            while(end_rep[i] <= 1000000){
                for(int j = start_rep[i]; j < end_rep[i]-1; j++){
                    if(bits[j] == 0) bits[j] = 1;
                    else return "CONFLICT";
                }
                start_rep[i] += interval_rep[i];
                end_rep[i] += interval_rep[i];
            }
        }
    }
    return "NO CONFLICT";
}
int main(void){
    for(;;){
        int n, m;
        std::cin >> n >> m;
        if(n == 0 && m == 0) break;
        int start_one[n], end_one[n], start_rep[m], end_rep[m], interval_rep[m]; 
        for(int i = 0; i < n; i++){
            //one-time tasks
            int h,j;
            std::cin >> h >> j;
            start_one[i] = h;
            end_one[i] = j;
        }
        for(int i = 0; i < m; i++){
            int h, j, l; //repeating tasks
            std::cin >> h >> j >> l;
            start_rep[i] = h;
            end_rep[i] = j;
            interval_rep[i] = l;
        }
        std::cout << verify_conflicts(n, m, start_one, end_one, start_rep, end_rep, interval_rep) << std::endl;

    }
}
// Analisar o pq do wrong answer