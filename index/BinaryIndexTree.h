#pragma once
#include <stdbool.h>

typedef struct TreeNode {
	char* word;
	struct List* lines;
	struct TreeNode* left;
	struct TreeNode* right;
	struct TreeNode* parent;
	bool visited;	
}TreeNode;

typedef struct Tree {
	TreeNode* root;
	
	int n;
} Tree;
TreeNode *create_TreeNode (char* word, int linenumber);
void destroyTree(Tree*t);
void preorderPrint(TreeNode *currnode);
Tree *create_Tree();
void InsertNodeInTree(char* word, int linenumber, TreeNode *beginNode, TreeNode *lastVisNode, int Mode, Tree *t);

void postorderDelete(TreeNode *currnode);