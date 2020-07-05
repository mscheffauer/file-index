#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BinaryIndexTree.h"
#include "List.h"
#include "string.h"
#include <stdbool.h>

Tree *create_Tree(){
	//allocate tree
	Tree *t = (Tree*) malloc(sizeof(Tree));	
	if (t == NULL){
		printf("memory exhausted \n");
		exit(EXIT_FAILURE);
	}
	t->root = NULL;	
	t->n = 0;	
	return t;
}


void preorderPrint(TreeNode *currnode){
	
	if (currnode != NULL)
	{
	
		if (currnode->visited == false){
			currnode->visited = true;
			printf("Treenode word: %s\n",currnode->word);
			printf("Treenode lines: "); 
			printList(currnode->lines);
			printf("\n");			
		}
	
		if ((currnode->left != NULL)  && (currnode->left->visited == false))
		{			
			preorderPrint(currnode->left);			
		}
		else if ((currnode->right != NULL)&& (currnode->right->visited == false))
		{	
			preorderPrint(currnode->right);			
		}
		else
		{		
			preorderPrint(currnode->parent);	
		}
		
	}
		
}

void postorderDelete(TreeNode *currnode){
	if (currnode != NULL)
	{
		if (currnode->left != NULL){		
			postorderDelete(currnode->left);	
		}else if (currnode->right != NULL){
			postorderDelete(currnode->right);	
		}else if ((currnode->left == NULL) && (currnode ->right == NULL)){
		
			TreeNode *next = currnode->parent;
							
			//both left and right are NULL, so free node
			if (currnode->parent != NULL){
				if (currnode->parent->left == currnode){
				
					currnode->parent->left = NULL;
							
				}else if (currnode->parent->right == currnode){
					
					currnode->parent->right = NULL;
				}				
			}
							
			if (currnode->lines != NULL){
				destroyList(currnode->lines);
			}			
				
			free(currnode->word);		
			free(currnode);	
			postorderDelete(next);		
		}
	}
	return;	
}

void destroyTree(Tree*t)
{
	//free tree
	if (t!= NULL){
		postorderDelete(t->root);	
		free(t);
	}
}

TreeNode *create_TreeNode (char* word, int linenumber){	

	TreeNode *n = (TreeNode*) malloc(sizeof(TreeNode));
	char *myword = (char*) malloc(strlen(word)+2);
		
	if ((myword == NULL) || (n == NULL)){
		printf("memory exhausted \n");
		exit(EXIT_FAILURE);
	}
	memset(myword,0,strlen(word)+2);
	strcpy(myword,word);
	
	//alle werte initialisieren
	n->left = NULL;
	n->right = NULL;
	n->parent = NULL;
	n->visited = false;

	n->lines = create_List();
	append(n->lines,linenumber);
	
	n->word = myword;
	
	return n;
}
//lastvisnode must be root at beginning

void InsertNodeInTree(char* word, int linenumber, TreeNode *beginNode, TreeNode *lastVisNode, int Mode, Tree *t)
{
	if (beginNode == NULL){
	
		
			TreeNode *newNode = create_TreeNode(word,linenumber);
			newNode->parent = lastVisNode;
			t->n++;			
			if (Mode == 0){			
				lastVisNode->left = newNode;
				
			}else{
				lastVisNode->right = newNode;
			}
						
	}else{

		if (strcmp(beginNode->word,word) < 0){			
			InsertNodeInTree(word,linenumber, beginNode->left, beginNode, 0, t);	
		}else if (strcmp(beginNode->word,word) > 0){				
			InsertNodeInTree(word,linenumber, beginNode->right, beginNode, 1, t);		
		}else{		
			//is the same so insert in node: add the line
			append(beginNode->lines,linenumber);
			
		}
		
	}
	
}
