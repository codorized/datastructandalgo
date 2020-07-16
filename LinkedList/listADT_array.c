/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct listnode{
    int size;
	int *list_array;
} LISTADT;

LISTADT *InitList(int max_size)
{
    LISTADT *L; 
    L = (LISTADT *)malloc(sizeof(LISTADT));
    
    if (L == NULL)
		printf("error:No SPACE!");
	else{
	    L->size = max_size;
        L->list_array = (int *)malloc(sizeof(int)*max_size);
        for(int i=0; i< max_size; i++)
        {
            L->list_array[i] = -1;
        }
	}
	
	return L;
}

void insertItem(LISTADT *myList, int value)
{
    for(int i=0; i<myList->size; i++)
    {
        if(myList->list_array[i] == -1)
        {
            myList->list_array[i] = value;
            return;
        }
    }
}

void deleteTail(LISTADT *myList)
{
    for(int i=0; i<myList->size; i++)
    {
        if(myList->list_array[i] == -1 )
        {
            if(i != 0)
            {
                myList->list_array[i-1] = -1;
            }
            return;
        }
    }
}

void printList(LISTADT *myList)
{
    for(int i=0; i<myList->size; i++)
    {
        printf("Value: %i ", myList->list_array[i]);
    }
}

int main()
{
    LISTADT *myList = InitList(5);
    
    insertItem(myList, 10);
    insertItem(myList, 20);
    insertItem(myList, 30);
    printf("Pre-Deletion: \n");
    printList(myList);
    printf("\n");
    deleteTail(myList);
    printf("Post-Deletion: \n");
    printList(myList);
   

    return 0;
}
