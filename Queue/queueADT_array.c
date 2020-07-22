#include <stdio.h>
#include <stdlib.h>

typedef struct stacknode{
    int size;
    int front;
    int rear;
    int *list_array;
} Q;

Q *InitQ(int max_size)
{
    Q *Qu; 
    Qu = (Q *)malloc(sizeof(Q));
    
    if (Qu == NULL)
        printf("error:No SPACE!");
    else{
        Qu->size = max_size;
        Qu->front = Qu->rear = 0;
        Qu->list_array = (int *)malloc(sizeof(int)*max_size);

    }
    
    return Qu;
}

void enq(Q **myQ, int value)
{
    if(((*myQ)->size) == (*myQ)->rear)
    {
        printf("The Q is full!\n");
        (*myQ)->rear = (*myQ)->size;
    }
    else
    {
        (*myQ)->list_array[(*myQ)->rear] = value;
        (*myQ)->rear++;
        printf("ENQ - front: %i and rear: %i \n ", (*myQ)->front, (*myQ)->rear);
    }
}

int deq(Q **myQ)
{
    int deqd_item = (*myQ)->list_array[(*myQ)->front];
    
    if((*myQ)->front != (*myQ)->rear)
    {
        (*myQ)->front++;
        printf("DQ - front: %i and rear: %i \n ", (*myQ)->front, (*myQ)->rear);
        
    }
    else
    {
        if((*myQ)->front != 0 && (*myQ)->rear != 0)
        {  
            (*myQ)->front = 0;
            (*myQ)->rear = 0;
            
        }
        
        printf("Q is empty. Cant enQ\n");
       
    }
    
    return deqd_item;
}



int main()
{
    Q *myQ = InitQ(5);
    
    enq(&myQ, 10);
    enq(&myQ, 20);
    enq(&myQ, 30);
    enq(&myQ, 10);
    enq(&myQ, 20);
    enq(&myQ, 30);
    deq(&myQ);
    deq(&myQ);
    deq(&myQ);
    deq(&myQ);
    deq(&myQ);
    deq(&myQ);
    deq(&myQ);
    
    return 0;
}
    