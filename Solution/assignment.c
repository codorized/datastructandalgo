#include <stdio.h>

int main()
{
    int b [5] = {7,8,5,3,2};
    int a = 10;
    int *d = &a;
    int *p = &b;
    int **c = &p;
    int *f = &*(b+4);
    int sum = 0;
    int sum1 = 0;
    int total = 0;
    
    // printf("%i\n", *f);
    
    for(int i = 0; i<=2;i++){
        sum += *(*c+i);
    }
    for(int i = 0; i<=1; i++){
        sum1 += *(f-i);
    }
    int product = sum * sum1;
    
    // printf("%i", product);
    
    total = product + *d;
    
    printf("%i", total);
}