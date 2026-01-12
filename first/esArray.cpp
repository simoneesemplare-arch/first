#include <stdio.h>
#include <stdlib.h>
void clear_ansi() {
printf("\e[1;1H\e[2J");
}
char Menu(){
    char scelta;
    printf("Menu:\n a) Inserire un numero nell'array\n b) Visualizzare una cella\n c) Visualizzare tutto l'array\n d) Visualizzare la somma di tutti i numeri nell'array\n e) Uscire dal programma\n");
    scanf(" %c",&scelta);
    return scelta;
}
int insertNumber(int array[], char conferma)
{
    int numero;
    int posizione;

    

    if (posizione < 1 || posizione > 10)
    {
        printf("posizione non valida\n");
    }
    else
    {
        if (array[posizione - 1] != 0)
        {
            printf("attenzione! stai sovrascrivendo un valore gia' presente nell'array, Continuare?(y/n)\n");
            scanf(" %c", &conferma);
            if (conferma == 'y')
            {
                array[posizione - 1] = numero;
            }
            else
            {
                printf("operazione annullata\n");
            }
        }
        else
        {
            array[posizione - 1] = numero;
        }
    }
}
int viewCell(int array[])
{
    int posizione;

    printf("inserire la posizione da visualizzare (1-10): ");
    scanf("%d", &posizione);

    if (posizione < 1 || posizione > 10)
    {
        printf("posizione non valida\n");
    }
    else
    {
        if (array[posizione - 1] != 0)
        {
            printf("il numero nella posizione %d e': %d\n", posizione, array[posizione - 1]);
        }
        else
        {
            printf("la posizione %d e' vuota\n", posizione);
        }
    }
}
int main() {
    int array[10]={0,0,0,0,0,0,0,0,0,0};
    bool tf=true;
    char scelta;
    char conferma;
    char avanti;
    while(tf){
        scelta = Menu();
        printf("inserire il numero da inserire nell'array: ");
        scanf("%d", &numero);
        printf("inserire la posizione in cui inserire il numero (1-10): ");
        scanf("%d", &posizione);

        if (scelta=='a' || scelta=='A'){

            
        }else if (scelta=='b' || scelta=='B'){

            
                
        }else if (scelta=='c' || scelta=='C'){

            for (int i = 0; i < 10; i++)
            {
                if(array[i]!=0){
                    printf("posizione %d: %d\n",i+1,array[i]);
                }
            }
        }else if (scelta=='d' || scelta=='D'){

            int somma=0;

            for (int i = 0; i < 10; i++)
            {
                somma+=array[i];
            }
            if(somma==0){
                printf("l'array e' vuoto\n");
            }else{
                printf("la somma di tutti i numeri nell'array e': %d\n",somma);
            }
        }    else if (scelta=='e' || scelta=='E'){
            tf=false;
        }else{
            printf("scelta non valida\n");
        }
        scanf(" %c",&avanti);
        clear_ansi();
    }
    return 0;
}