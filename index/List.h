#pragma once

typedef struct ListNode {
	uint32_t linenumber;
	struct ListNode* next;
	struct ListNode* prev;
		
}ListNode;

typedef struct List {
	ListNode* first;
	ListNode* last;
	int n;
} List;
List *create_List();
int count(List *l);
void append(List* l, int linenumber);
void printList(List* l);
ListNode *create_ListNode(int linenumber);
void destroyList(List*l);