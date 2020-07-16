#include <stdio.h>
#include <stdlib.h>

typedef struct stacknode{
    int value;
    struct stacknode *next;
} STACK;

void push(STACK **top, int value)
{
   
  STACK *newNode = malloc(sizeof(STACK));
  
  newNode->value = value;
  newNode->next = NULL;
 
  if(*top == NULL) 
  {
    *top = newNode;
    return;
  }
  else 
  {
    newNode->next = *top;
    *top = newNode;
  }
   return;
}

int pop(STACK **top)
{
    if(*top != NULL)
    {
        STACK *toDelete = *top;
        int temp;
        *top = (*top)->next;
        toDelete->next = NULL;
        temp = toDelete->value;
        free(toDelete);
        return temp;
    }
    else
    {
        printf("Stack is EMPTY!");
        return -1;
    }
}

int main()
{
    STACK *top = NULL;
    
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    
    printf("%i\n", pop(&top));
    printf("%i\n", pop(&top));
    printf("%i\n", pop(&top));
    printf("%i\n", pop(&top));
    push(&top, 30);
    printf("%i\n", pop(&top));

    return 0;
}
