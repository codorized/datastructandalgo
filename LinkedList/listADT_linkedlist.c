#include <stdio.h>
#include <stdlib.h>

typedef struct listnode{
    int value;
    struct listnode *next;
} LISTADT;

void insertItem(LISTADT **head, int value)
{
   
  LISTADT *newNode = malloc(sizeof(LISTADT));
  LISTADT *tail = *head;
  
  newNode->value = value;
  newNode->next = NULL;
 
  if(*head == NULL) 
  {
    *head = newNode;
    return;
  }
  else 
  {
    while(tail->next != NULL)
  {
    tail = tail->next;
  }
  
  tail->next = newNode;

  }
   return;
}

void printList(LISTADT *head)
{
    do
    {
        printf("Value: %i\n", head->value);
        head=head->next;
    }
    while(head != NULL);
  
    return;
}

void deleteTail(LISTADT **head)
{
  LISTADT *nxt = *head;
  LISTADT *prv = *head;

  while(nxt->next != NULL)
  {
    prv = nxt;
  nxt = prv->next;
  }
  
  prv->next = NULL;
  free(nxt);

  return;
}

int main()
{
    LISTADT *head = NULL;
    
    insertItem(&head, 25);
    insertItem(&head, 35);
    insertItem(&head, 45);
    insertItem(&head, 55);
    
    printf("Pre-Deletion\n");
    printList(head); 
    
    deleteTail(&head);
    printf("Post-Deletion\n");
    printList(head);

    return 0;
}
