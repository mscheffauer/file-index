#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"


List *create_List(){
	//allocate list
	List *l = (List*) malloc(sizeof(List));	
	if (l == NULL){
		return NULL;
	}
	l->first = NULL;
	l->last = NULL;
	l->n = 0;
	
	return l;
}

void printList(List* l){
	ListNode* temp = NULL;
	
	printf("%d",l->first->linenumber);
	temp = l->first->next;
	
	for (int i=0; i<(l->n-1);i++ ){
		
		printf(", %d",temp->linenumber);
		temp = temp->next;
    }
	
}

void destroyList(List*l){

	ListNode* nodetoFree;
	if (l->first != NULL){
		nodetoFree = l->first;
	}
	
	while (nodetoFree->next != NULL){	
		nodetoFree = nodetoFree->next;
	
		free(nodetoFree->prev);
	}
	
	free(l->last);
	
	//free list
	if (l!= NULL){
		free(l);
	}
}

ListNode *create_ListNode (int linenumber){	
	ListNode *n = (ListNode*) malloc(sizeof(ListNode));
	
	if (n == NULL){
		return NULL;
	}
	//alle werte initialisieren
	n->linenumber = linenumber;
	n->next = NULL;
	n->prev = NULL;
	
	return n;
}
void append(List* l, int linenumber){
	ListNode* new_Node = create_ListNode(linenumber);
	
	if (new_Node == NULL){
		printf("memory exhausted\n");
	}else{
		if (l->last != NULL){
			l->last->next = new_Node;
		}
		
		new_Node->prev = l->last;	//next of new node is current first of list
		
			//new last of list is new node
		l->last = new_Node;
		if (l->n==0){
			l->first = new_Node;
		}
		
		l->n++;
	}
	
}