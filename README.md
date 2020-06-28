### Data Structures and Algorithms

## Topic 1: Pointers
# Intro 
Pointers are variables that store addresses and of course have their own addresses as well. 

# Referencing and Dereferencing
1. Referencing -  getting the address of the pointed variable. This uses ```&```  <br>
**Declaration:** <br> 
``` int *a = &c; ``` <br>
**Explanation:** <br>
```a``` is an integer pointer which points to the address of integer variable ```c```  <br>
**Visual:** <br>
```a --> [x0005][c] ``` <br>
NOTE: Datatypes of pointers depends on the datatype of the variable it is pointing to.  <br>

2. Dereferencing - getting the value from the address that is pointed by the pointer. This uses ```*``` <br>
``` printf("%i", *a) ``` <br>
**Explanation:** <br>
since ```a``` is an pointer, it contains the address itself. To get the value of the variable of the one ```a``` is pointing to, u need to add ```*``` so it becomes ```*(a)``` or just simply ```*a```. <br>

# Pointer to a pointer?
These are pointers which contain the address of the pointer it is pointing to. <br>
**Declaration:** <br>
``` int a = 10; ``` <br>
``` int *b; ``` <br>
``` int **c; ``` <br>	
``` b = &a; ```<br>
``` c = &b; ``` <br>
```printf("The value of a via pointer c is: %i", **c)```

## Topic 2: D&A Overview
# Datatypes vs Abstract Datatypes (ADTs) 
Datatypes | ADTs
------------ | -------------
set of values that a variable may assume | mathematical model, together with various operations defined on the model
Examples: boolean, integer, double etc. | Examples: Stack -> Push and Pop; Queue -> Enqueu and Dequeue etc. 

# Data Structure
Collections of variables, possibly of several different data types, connected in various ways.
Examples: Array, Linked-lists (Singly, Doubly), Adjacency Matrix, Adjecency List etc.

# List ADT
A sequence of zero or more elements of the same type. In List ADT, there are two implementations: Array or Linked List Implementation. 
**Operations:**
Traverse, Insert, Delete

# Array Implementation
**Initialization:**
```
int a[10];
//Initialize all indices to -1(empty slot)
for(int i=0; i<10; i++){
  a[i] = -1;
}
```
**Operation: TRAVERSE** 
```
for(int i=0; i<10; i++){
  if(a[i] != -1)
    printf("%i", a[i]);
}
```
**Operation: INSERT** 
```
for(int i=0; i<10; i++){
  if(a[i] == -1)
  {
      a[i] = value;
  }
}
```
# Linked-list Implementation
**Initialization:**
```
#include <stdio.h>
#include <stdlib.h>

typedef struct listnode{
    int value;
    struct listnode *next;
} LISTADT;
```
**Operation: INSERT** 
```
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
```
**Operation: TRAVERSE** 
```
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


int main()
{
    LISTADT *head = NULL;
    insertItem(&head, 25);
    insertItem(&head, 35);
    insertItem(&head, 45);
    insertItem(&head, 55);
   
    printList(head);

    return 0;
}
```





