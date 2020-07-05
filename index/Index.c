#include <stdio.h>
#include <stdlib.h>
#include "BinaryIndexTree.h"
#include "List.h"
#include "string.h"
#include <stdbool.h>
#include <ctype.h>

static Tree *t = NULL;



bool hasCharacter(char*c)
{
	for (size_t i=0; i<strlen(c);i++ ){
		if (isspace(c[i])==0){
			return true;
		}
	}
	return false;
}



void Create(void){
	t = create_Tree();
}
// add word with line number to index 
void Add(char *word, int lineNumber){

	if (t->root == NULL){
	
		TreeNode *newNode = create_TreeNode(word, lineNumber);
		if (newNode != NULL){
			
			t->root = newNode; 
			t->n++;
		}else{
				printf("memory exhausted \n");
			exit(EXIT_FAILURE);
		}
		
	}else{
	
		InsertNodeInTree(word, lineNumber,t->root, t->root, 0, t);
	}

} 
// remove all words from index, afterwards new words can be added with Add 
void Clear(void){

	if (t!= NULL){
		postorderDelete(t->root);	
		t->root = NULL;
		t->n = 0;
	}

} 
// print index on standard output 
void Print(void){
	
	printf("Tree with %d elements\n\n",t->n);
	
	if (t != NULL){
		preorderPrint(t->root);
	}
}


void Delete(void)
{
	destroyTree(t);
}


void AddItemsFromBuffer(char* textptr, uint32_t linecounter) {
	//NOTE: not const char* text = "1 23 x 6"
	//strtok changes string!
	
	uint32_t tokennum;
	char* tokenptr;  
	
	for(tokennum = 1; (tokenptr = strtok(textptr, " \n")) != NULL; textptr = NULL, tokennum++) {

		uint32_t len=strlen(tokenptr);
		uint32_t somenum = strcspn(tokenptr, ",.?!");
		//remove trailing characters
		if (somenum == (len - 1)){
		
			tokenptr[len-1] = '\0';	
		}else if (somenum != len){
		
			bool flag = false;
			for (uint32_t i=somenum; i<len;i++ ){
				
				if ((tokenptr[i] != ',') && (tokenptr[i] != '.') && (tokenptr[i] != '!') && (tokenptr[i] != '?')){
				
					flag = false;
					break;
				}else{		
					flag = true;
				}
			}
			if (flag == true){
			
				tokenptr[somenum] = '\0';
			}			
		}
		
		if (strlen(tokenptr) > 0){	
		
			 if (hasCharacter(tokenptr) == true)
			{
				Add(tokenptr,linecounter);
			}
		}	
		
	
	}
	
}



