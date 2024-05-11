// 1. Defining a data type consists of deciding how to store the data and
// designing a set of functions to manage the data.

// 2. The list can be traversed in only one direction because each structure
// contains the address of the next structure,but not of the preceding
// structure.You could modify the structure definition so that each structure
// contains two pointers—one to the preceding structure and one to the next
// structure.The program,	of course,would have to assign proper addresses to
// these pointers each time a new structure is added.

/* 3. An ADT is an abstract data type, a formal definition of the properties of
a type and of the operations that can be performed with the type. An ADT should
be expressed in general terms, not in terms of some specific computer language
or implementation details */

/* 4. Advantages of passing a variable directly: This function inspects a queue,
but should not alter it. Passing a queue variable directly means the function
works with a copy of the original, guaranteeing that the function does not alter
the original data. When passing a variable directly, you don’t have to remember
to use the address operator or a pointer. Disadvantages of passing a variable
directly: The program has to allocate enough space to hold the variable and then
copy information from the original to the copy. If the variable is a large
structure, using it has a time and space penalty. Advantages of passing the
address of a variable: Passing an address and accessing the original data is
faster and requires less memory than passing a variable if the variable is a
large structure.
 Disadvantages of passing the address of a variable: You have to remember to use
the address operator or a pointer. Under K&R C, the function could inadvertently
alter the original data, but you can overcome this objection with the ANSI C
const qualifier. */

/* 5. a.
Type Name: Stack.
Type Properties: Can hold an ordered sequence of items.
Type Operations: Initialize stack to empty.
Determine whether stack is empty.
Determine whether stack is full.
Add item to top of stack (pushing an item).
Remove and recover item from top of stack (popping an item).

 b. The following implements the stack as an array, but that information affects
only the structure definition and the details of the function definitions; it
doesn’t affect the interface described by the function prototypes. */

/* stack.h –– interface for a stack */
#include <stdbool.h>
/* INSERT ITEM TYPE HERE */
/* FOR EXAMPLE, typedef int Item; */
#define MAXSTACK 100

typedef struct stack {
	Item items[MAXSTACK]; /* holds info */
	int top;			  /* index of first empty slot */
} Stack;

/* operation: initialize the stack */
/* precondition: ps points to a stack */
/* postcondition
: stack is initialized to being empty */
void InitializeStack(Stack *ps);
/* operation: check if stack is full */
/* precondition: ps points to previously initialized stack */
/* postcondition: returns true if stack is full, else false */
bool FullStack(const Stack *ps);
/* operation: check if stack is empty */
/* precondition: ps points to previously initialized stack */
/* postcondition: returns true if stack is empty, else false */
bool EmptyStack(const Stack *ps);
/* operation: push item onto top of stack */
/* precondition: ps points to previously initialized stack */
/* item is to be placed on top of stack */
/* postcondition: if stack is not full, item is placed at */
/* top of stack and function returns */
/* true; otherwise, stack is unchanged and */
/* function returns false */
bool Push(Item item, Stack *ps);
/* operation: remove item from top of stack */
/* precondition: ps points to previously initialized stack */
/* postcondition: if stack is not empty, item at top of */
/* stack is copied to *pitem and deleted from */
/* stack, and function returns true; if the */
/* operation empties the stack, the stack is */
/* reset to empty. If the stack is empty to */
/* begin with, stack is unchanged and the */
/* function returns false */
bool Pop(Item *pitem, Stack *ps);