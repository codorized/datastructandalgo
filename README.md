### Data Structures and Algorithms

## Topic 1: Pointers
# Intro 
Pointers are variables that store addresses and of course have their own addresses as well. 

# Two types of operation in pointers
1. Referencing -  getting the address of the pointed variable. This uses ```&``` 
#Implementation
Declaration: 
``` int *a = &c; ```
Explanation:
```a``` is an integer pointer which points to the address of integer variable ```c```  
Visual:
```a --> [x0005][c] ```
NOTE: Datatypes of pointers depends on the datatype of the variable it is pointing to. 

2. Dereferencing - getting the value from the address that is pointed by the pointer. This uses ```*``` <br>
``` printf("%i", *a) ```
Explanation: 
since ```a``` is an pointer, it contains the address itself. To get the value of the variable of the one ```a``` is pointing to, u need to add ```*``` so it becomes ```*(a)``` or just simply ```*a```. 

# Pointer to a pointer? 
These are pointers which contain the address of the pointer it is pointing to. 
Declaration: 
``` int a = 10; ``` <br>
``` int *b; ``` <br>
``` int **c; ``` <br>	
``` b = &a; ```<br>
``` c = &b; ```<br>

<br>
``` printf("The value of a via pointer c is: %i", **c) ```





