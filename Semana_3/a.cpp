#include <iostream> 
#include <algorithm> 
#include <string.h>
#include <ctype.h>

int main () {
    char arrayChar[51];
    while(1){
        scanf("%s", arrayChar);
        int size = strlen(arrayChar);
        if(arrayChar[0] == '#') break;
        if(std::next_permutation(arrayChar, arrayChar+size)) std::cout << arrayChar << std::endl;
        else std::cout << "No Successor" << std::endl;
    }
}