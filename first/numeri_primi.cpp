#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    else if (n == 2) return 1;
    else if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int num;
    int arrivo;
    printf("Inserisci un numero: ");
    scanf("%d", &num);
    printf("Inserisci il numero di quanti numeri primi vuoi: ");
    scanf("%d", &arrivo);
    int i = 0;
    while(i!=arrivo){
        if (isPrime(num)){
            printf("%d e' un numero primo\n", num);
            i++;
        }
        num++;
    }
    
    return 0;
}