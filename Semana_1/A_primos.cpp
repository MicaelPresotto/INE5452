#include <iostream>
#include <vector>

const int MAX = 1000000; // Limite máximo para pré-computar números primos

int main() {
    // Pré-computar números primos até MAX usando o Algoritmo da Peneira de Eratóstenes
    std::vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Armazenar os números primos em um vetor
    std::vector<int> primes;
    for (int i = 2; i <= MAX; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    int n;
    std::cin >> n;

    for (int _ = 0; _ < n; ++_) {
        int a, b;
        std::cin >> a >> b;

        if (a < 2) a = 2; // Garantir que a seja pelo menos 2

        std::vector<bool> rangeIsPrime(b - a + 1, true);
        for (int prime : primes) {
            if (prime * prime > b) break; // Não precisamos verificar primos maiores que a raiz de b
            int start = std::max(prime * prime, (a + prime - 1) / prime * prime);
            for (int j = start; j <= b; j += prime) {
                rangeIsPrime[j - a] = false;
            }
        }

        for (int i = a; i <= b; ++i) {
            if (rangeIsPrime[i - a]) {
                std::cout << i << '\n';
            }
        }

        std::cout << '\n';
    }

    return 0;
}