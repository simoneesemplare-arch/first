#include <stdio.h>

int fattoriale(int n,int risultato) {
    
    for (int i = n; i !=1; i--)
    {
        risultato=risultato*i;
    }
    return risultato;
}

int main() {
    int risultato=1;
    printf("inserire un numero per calcolarne il fattoriale: ");
    int num;    
    scanf("%d",&num);
    printf("il fattoriale di %d e': %d",num,fattoriale(num,risultato));   
    
    return 0;
}