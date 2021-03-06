#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
bool is_number(char *str)
{
    // Returns false if any character in str is not an element of {0,...,9}
    for (int index = 0; index < strlen(str); index++){
        if (!isdigit(str[index])) return false;
    }
    return true;
}



int main(int argc, char *argv[])
{

    int a = atoi(argv[1]);
    int b = atoi(argv[2]); 
    
    int aTmp = a;
    int bTmp = b;
    
    char *aStr = argv[1];
    char *bStr = argv[2];
    
    if (!(a >= 1 && is_number(aStr)) && 
        !(b >= 1 && is_number(bStr))) {
        printf("ERROR: gcd(a,b) only works on positive integers!");
        printf("\na = %s\nb = %s\n\n",aStr,bStr);
        return 0;
    }
    
    while (1){ // While true, could cause infinite loop
        if (aTmp == bTmp){ 
            // Found gcd(a, b), print it, and return success.
            printf("gcd(%d,%d)=%d\n\n", a, b, aTmp);
            return 0;
        }else if (aTmp > bTmp) {
            aTmp = aTmp - bTmp; 
        }else {
            bTmp = bTmp - aTmp;
        }
    }
    
    
    return 0;
}