    #include <stdio.h>
    
    int main() {
        const int size=5;
        int voti[size];
        float media=0;
        for(int i=0;i<size;i++){
            printf("inserisci il voto %d: ",i+1);
            scanf("%d",&voti[i]);
            media+=voti[i];
        }
        printf("la media e': %0.2f \n",media/5);
        for (int i = 0; i < size; i++)
        {
            printf("voto %d: %d\n",i+1,voti[i]);     
        }
        

        return 0;
    }