#include <stdio.h>
int main(){
    int num=0;
    int divisore=1;
    printf("inserire un numero");
    scanf("%d",&num);
    int calcolatore=num/2;
    if (num==1)
    {
        printf("il massimo comun divisore e': 1");
        return 0;
    }else{
    
        if (num%2==0)
        {
            printf("il massimo comun divisore e': %d",calcolatore);
        }else
        {
            for (int i = num-1; i!=2; i--)
            {
                if (num%i==0)
                {
                    printf("il massimo comun divisore e': %d",i);
                    return 0;   
                }
                
            }
             divisore=1;    
        }
        printf("il massimo comun divisore e': %d",divisore);
    }
    
    return 0;
}