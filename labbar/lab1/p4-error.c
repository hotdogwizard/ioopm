#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a2,a1;
  
    if ((a1 = atoi(argv[1]);) || 
        (a2 = atoi(argv[2]);)){
   
    for (int i = 1; i <= a1; i+=1){
        for (int j = 1; j <= a2*i; j+=1){
                   printf("*");
        }
        
        printf("\n");
    }

    return 0;
        }
        return 1;
}