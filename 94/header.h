#ifndef HEADER_H_
#define HEADER_H_

#include <stdbool.h>

struct TreeNode{
	
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


struct Queue{
	struct QueueNode *head, *tail;
};

struct QueueNode{

	struct TreeNode* treeNode;
	struct QueueNode *next;
};


struct Stack{
	int top;
	struct TreeNode **vect;
};

//tree functions
//int createTree(struct TreeNode **root);
struct TreeNode* create();
struct TreeNode* insertNode(int value);
void deleteNode(struct TreeNode *root);
void inorderTraversal(struct TreeNode *root, FILE *out);

//queue functions
struct Queue* initQueue();
void putQueue(struct Queue *queue, struct TreeNode* node);
struct TreeNode* getQueue(struct Queue* queue);
bool isEmptyQueue(struct Queue* queue);

//array functions
void printArray(int *array, int size, FILE *out);

//stack functions
void pushStack(struct Stack *stack, struct TreeNode *root);
void popStack(struct Stack *stack);
struct TreeNode* topStack(struct Stack *stack);
bool isEmptyStack(struct Stack stack);
void initStack(struct Stack *stack, int size);
int *inorderTraversalIterative(struct TreeNode *root, int size);

#endif
