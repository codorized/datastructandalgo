int main()
{
    int a [4] = {25,10,5,7};
    int *q = &a;
    int **p = &q;
    int sum = 0;
    
    for(int i = 0; i<4;i++){
        
        sum += *(*p+i);
        
    }
    printf("%i\n", sum);
    // printf("%i\n", *(q+1));
    // printf("%i", *(*p+1));
}
