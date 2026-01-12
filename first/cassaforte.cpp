#include <stdio.h>
#include <string.h>

int main() {
    int codice=0;
    FILE *file = fopen("long.txt", "r");
    if (!file) return 1;
    int num=0;
    char direzione;
    char spostamento[8];
    int manopola=50;
    while (fgets(spostamento, sizeof(spostamento), file)){
        sscanf(spostamento, "%c%d", &direzione, &num);
        if(direzione=='R'){
            manopola=manopola+num;
            while(manopola>99){
                manopola=manopola-100;
                codice++;
            }
        }else if(direzione=='L'){
            if(manopola==0){
                manopola=manopola-num;
                while(manopola<0){
                    manopola=manopola+100;
                    codice++;
                }
                codice--;
            }else{
                manopola=manopola-num;
                while(manopola<0){
                    manopola=manopola+100;
                    codice++;
                }
            }
        }
        if(manopola==0){
            codice++;
        }
        printf("lo spostamento e': %s",spostamento);
        printf("la combinazione attuale della cassaforte e': %d\n",manopola);
        printf("il codice attuale e': %d\n",codice);
    }
    fclose(file);
}