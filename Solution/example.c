#include <stdio.h>
#include <stdlib.h>

typedef struct listnode{
    int value;
    struct listnode *next;
} LISTADT;

void insertElement(LISTADT **head, int value)
{
    LISTADT *nn; 
    nn = malloc(sizeof(LISTADT));
    nn->value = value;
    nn->next = NULL;
    
    if(*head == NULL)
    {
        *head = nn;
    }
    else
    {
        LISTADT *tail = *head;
        
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        
        tail->next = nn;
    }
}

void printList(LISTADT *head)
{
    LISTADT *ptr = head;
    while(ptr != NULL)
    {
        printf("%i\n", ptr->value);
        ptr=ptr->next;
    }
}

void deleteList(LISTADT **hd){
	
	LISTADT *nxt = *hd;
	LISTADT *prev = *hd;
	
	while(nxt->next != NULL){
		prev = nxt;
		nxt=nxt->next;
	}
	free(nxt);
	nxt = NULL;
	prev->next = NULL;
}

int main()
{
    LISTADT *head = NULL;
    
    insertElement(&head, 10);
    insertElement(&head, 20);
    insertElement(&head, 30);
    insertElement(&head, 40);
    insertElement(&head, 50);

    printList(head);
	deleteList(&head);
	printf("\n");
	printList(head);
	deleteList(&head);
	printf("\n");
	printList(head);
    return 0;
}
