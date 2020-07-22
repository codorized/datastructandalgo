#include <stdio.h>
#include <stdlib.h>

typedef struct qnode{
    int value;
    struct qnode *next;
} Q;

void enq(Q **front, Q **rear, int value)
{
   
  Q *newNode = malloc(sizeof(Q));
  newNode->value = value;
  newNode->next = NULL;
 
  if(*front == NULL) 
    *front = newNode;
  else 
    (*rear)->next = newNode;
   
  *rear = newNode;

}

int deq(Q **front, Q **rear)
{
  if(*front != NULL)
  {
     Q *toDeletePtr = *front; 
     int toDeleteItem = toDeletePtr->value;

     *front = (*front)->next; 

     toDeletePtr->next = NULL;
     free(toDeletePtr);

     return toDeleteItem;
  }
  
  printf("Queue is Empty! Can't DQ");
  return -1;
}

int main()
{
    Q *front = NULL;
    Q *rear = NULL;

    enq(&front, &rear, 10);
    enq(&front, &rear, 20);
    printf("%i\n", deq(&front, &rear));
    printf("%i\n", deq(&front, &rear));
    printf("%i\n", deq(&front, &rear));
   

    return 0;
}
