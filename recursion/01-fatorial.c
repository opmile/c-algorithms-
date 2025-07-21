#include <stdio.h>

int fatorial(int n);

int main() {

    int number = 5;
    printf("fatorial de %d é: %d\n", number, fatorial(number));

    return 0;
}

int fatorial(int n) {
    // caso base (condição de parada): 0! = 1
    if (n == 0) {
        return 1;
    } else { // caso normal
        return n * fatorial(n - 1);
    }
}