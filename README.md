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
  ```
  **Operation: DELETE** 
  ```Exercise```
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

  **Operation: DELETE** 
  ```Exercise```

  # STACK ADT
  The Stack ADT. A Stack is a collection of objects inserted and removed according to the Last In First Out (LIFO) principle. In Stack ADT, there are two implementations: Array or Linked List Implementation. 
  # Array Implementation
  **Initialization:**
  ```
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
  ```
  **Operation: PUSH** 
  ```
  void push(STACK **myStack, int value)
  {
      (*myStack)->list_array[(*myStack)->TOS] = value;
      (*myStack)->TOS++;
  }
  ```
  **Operation: POP** 
  ```
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
  ```

  # Linked List Implementation
  **Initialization:**
  #include <stdio.h>
  #include <stdlib.h>
  ```
  typedef struct stacknode{
      int value;
      struct stacknode *next;
  } STACK;
  ```
  **Operation: PUSH** 
  ```
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

  **Operation: POP** 
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
  ```

  ```Exercise```
  Create two related, linked-list implemented stacks S1 and S2 with the following operations: 
  1. push(Si,value): push element in stack Si where i can be 1 or 2;
  2. pop(Sj,Sk): Sj will be popped. The popped element will be pushed to Sk.

  ```Assignment```
  Advanced Study: Queues


# QUEUE ADT
 Queue ADT is a collection of similar data items in which insertion and deletion operations are performed based on FIFO principle"
  # Array Implementation
  **Initialization:**
  ```
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
  ```
  **Operation: ENQUEUE** 
  ```
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
  ```
  **Operation: DEQUEUE** 
  ```
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
  ```

  # Linked List Implementation
  **Initialization:**
 ```
 typedef struct qnode{
    int value;
    struct qnode *next;
} Q;
  ```
  **Operation: ENQUEUE** 
  ```
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
```

  **Operation: DEQUEUE** 
  ```
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
  ```

  ```Exercise```
  Create a linklist-implement Queue which only allows 3-char string to be enqueued. Each Q node is characterized by:
  1. value
  2. array of size 3
  
  Mods to operations: 
  Enqueue: enq(&myQ, "hey"); 
  Dequeue: deq(&myQ); this now displays the string of the dequeued node. 

  ```Challenge```
Create a circular Queue using a dynamic array.

  ```Assignment```
Advanced Study: Sorting Algorithms

