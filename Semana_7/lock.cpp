// tipo especial de cadeado
// ferulock
// sempre mostra valores de 4 digitos tem um codigo especifico para dar unlock
// o cadeado eh aberto quando o codigo eh digitado
// o codigo para abrir pode aparece rapido com ajudas de uns botoes
// que tem um numero associado a eles
// quando um botao eh pressionado o numero associado a eles eh adicionado
// o cadeado sempre usa pelo menos 4 significantes adicoes

//input
// terao while true casos testes
// para cada caso teste tera 3 numeros L U R 
// L representa o atual codigo do cadeado
// U representa o codigo que abre o cadeado
// R representa o numero de botoes
// tera R numeros in uma linha indicado o valor dos botoes

// output
// para cada caso teste
// imprimir o numero numero de botoes pressionados para abrir o cadeado
// caso nao seja possivel imprimir Permantly Locked


#include <iostream>
#include <vector>

int main(void){
    for(;;){
        int l, u , r; std::cin >> l >> u >> r;
        if(l == 0 && u == 0 && r == 0) break;
        std::vector<int> buttons(r);
        for(int i = 0; i < r; i++){
            std::cin >> buttons[i];
        }
    }
}