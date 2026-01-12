#include <stdio.h>

int pow(int base, int esponente) {
    int risultato = 1;
    for (int i = 0; i < esponente; i++) {
        risultato *= base;
    }
    return risultato;
}



int main() {
    int base, esponente;
    printf("inserire la base: ");
    scanf("%d", &base); 
    printf("inserire l'esponente: ");
    scanf("%d", &esponente);
    printf("%d elevato a %d e': %d\n", base, esponente, pow(base, esponente));
    return 0;
}