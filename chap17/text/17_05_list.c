/* list.c -- functions supporting list operations */
#include "17_03_list.h"
#include <stdio.h>
#include <stdlib.h>

/* local function prototype */
static void CopyToNode(Item item, Node *pnode);

/* interface functions   */
/* set the list to empty */
void InitializeList(List *plist) { *plist = NULL; } /* Setting head to NULL */

/* returns true if list is empty */
bool ListIsEmpty(const List *plist) {
	if (*plist == NULL) /* by checking if the head node is NULL */
		return true;
	else
		return false;
}

/* returns true if list is full */
bool ListIsFull(const List *plist) {
	Node *pt;
	bool full;
	pt = (Node *)malloc(sizeof(Node)); /* Attempt to add a new node */
	if (pt == NULL)					   /* if adding a node failed, it's full */
		full = true;
	else
		full = false;
	free(pt);
	return full;
}

/* returns number of nodes */
unsigned int ListItemCount(const List *plist) {
	unsigned int count = 0;
	Node *pnode = *plist; /* set to start of list */

	while (pnode != NULL) {
		++count;
		pnode = pnode->next; /* set to next nodex    */
	}
	return count;
}

/* creates node to hold item and adds it to the end of */
/* the list pointed to by plist (slow implementation)  */
bool AddItem(Item item, List *plist) {
	Node *pnew;
	Node *scan = *plist; /* *scan is used to traverse the linked list */

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false; /* quit function on failure  */

	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (scan == NULL)  /* empty list, so place */
		*plist = pnew; /* pnew at head of list */
	else {
		while (scan->next != NULL)
			scan = scan->next; /* find end of list    */
		scan->next = pnew;	   /* add pnew to end     */
	}

	return true;
}

/* visit each node and execute function pointed to by pfun */
void Traverse(const List *plist, void (*pfun)(Item item)) {
	Node *pnode = *plist; /* set to start of list   */

	while (pnode != NULL) {
		(*pfun)(pnode->item); /* apply function to item */
		pnode = pnode->next;  /* advance to next item   */
	}
}

/* free memory allocated by malloc() */
/* set list pointer to NULL          */
void EmptyTheList(List *plist) {
	Node *psave;

	while (*plist != NULL) {
		psave = (*plist)->next; /* save address of next node */
		free(*plist);			/* free current node         */
		*plist = psave;			/* advance to next node      */
	}
}

/* local function definition  */
/* copies an item into a node */
static void CopyToNode(Item item, Node *pnode) {
	pnode->item = item; /* structure copy */
}
