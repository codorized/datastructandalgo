#include <stdio.h>
#include <stdlib.h>

typedef struct stacknode{
    int size;
    int TOS; 
	int *list_array;
} STACK;

STACK *InitStack(int max_size)
{
    STACK *S; 
    S = (STACK *)malloc(sizeof(STACK));
    
    if (S == NULL)
		printf("error:No SPACE!");
	else{
	    S->size = max_size;
	    S->TOS = 0;
        S->list_array = (int *)malloc(sizeof(int)*max_size);
        for(int i=0; i< max_size; i++)
        {
            S->list_array[i] = -1;
        }
	}
	
	return S;
}

void push(STACK **myStack, int value)
{
    (*myStack)->list_array[(*myStack)->TOS] = value;
    (*myStack)->TOS++;
}

int pop(STACK **myStack)
{
    
    if((*myStack)->TOS > 0)
    {
        int poppedItem;
        poppedItem = (*myStack)->list_array[((*myStack)->TOS)-1];
        (*myStack)->TOS--;
        return poppedItem;
    }
    
    printf("No Item to Pop!");
    return -1;
    
}



int main()
{
    STACK *myStack = InitStack(5);
    push(&myStack, 5);
    push(&myStack, 10);
    push(&myStack, 15);
    
    printf("%i\n", pop(&myStack));
    printf("%i\n", pop(&myStack));
    printf("%i\n", pop(&myStack));
    printf("%i\n", pop(&myStack));
    push(&myStack, 15);
    printf("%i\n", pop(&myStack));

    return 0;
}
