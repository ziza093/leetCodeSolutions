#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

//doesnt work if I have NULL inside the numbers, didnt want to waste 
//time patching this knowing the inorder traversal function matters for leetCode


//used a queue to create the tree in the form the problem wants
struct TreeNode* create(){
	FILE *in = 0;
	int n = 0;
	in = fopen("input.txt", "r");
	
	if(!in){
		fprintf(stderr, "File didn't open!\n");
		exit(EXIT_FAILURE);
	}
	
	fscanf(in, "%d", &n);
	struct TreeNode* root = insertNode(n);
	struct Queue *queue = initQueue();
	putQueue(queue, root);

	while(!isEmptyQueue(queue)){
		struct TreeNode* help = getQueue(queue);

		if(fscanf(in, "%d", &n) == 1){
			if(n != EOF){
				struct TreeNode *leftNode = insertNode(n);
				help -> left = leftNode;
				putQueue(queue, leftNode);
			}
			else{
				if(fscanf(in, "%d", &n) == 1){
					if(n == EOF){
						break;
					}
				}
			}
		}

		if(fscanf(in, "%d", &n) == 1){
			if(n != EOF){
				struct TreeNode *rightNode = insertNode(n);
				help -> right = rightNode;
				putQueue(queue, rightNode);
			}
			else{
				if(fscanf(in, "%d", &n) == 1){
					if(n == EOF){
						break;
					}
				}
			}
		}
	}
	
	fclose(in);
	in = 0;

	return root;
}


struct TreeNode* insertNode(int value){
	
	struct TreeNode *temp = 0;

	temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));

	temp -> val = value;
	temp -> left = 0;
	temp -> right = 0;

	return temp;
}

//recursive method
void inorderTraversal(struct TreeNode *root, FILE *out){

	if(!out){
		fprintf(stderr, "File didn't open correctly!\n");
		exit(EXIT_FAILURE);
	}

	if(!root){
		return;
	}
	else{
		if(root -> left){
			inorderTraversal(root -> left, out);
		}
		
		fprintf(out, "%d ", root -> val);
		
		if(root -> right){
			inorderTraversal(root -> right, out);
		}
	}
	
}

//queue functions
struct Queue* initQueue(){
	
	struct Queue* queue = 0;
	queue = (struct Queue*)malloc(sizeof(struct Queue));

	queue -> head = NULL;
	queue -> tail = NULL;

	return queue;
}

void putQueue(struct Queue *queue, struct TreeNode* node){
	//insert node in queue
	struct QueueNode* queueNode = 0;
	queueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));

	queueNode -> treeNode = node;
	queueNode -> next = NULL;

	if(queue -> tail == NULL){
		queue -> head = queueNode;
		queue -> tail = queueNode;
	}
	else{
		queue -> tail -> next = queueNode;
		queue -> tail = queueNode;
	}
}

struct TreeNode* getQueue(struct Queue* queue){
	if(queue -> head == NULL)
		return NULL;

	struct QueueNode* aux = queue -> head;
	struct TreeNode * node = aux -> treeNode;
	queue -> head = queue -> head -> next;

	if(queue -> head == NULL){
		queue -> tail = NULL;
	}
	
	memset(aux, 0, sizeof(struct QueueNode));
	free(aux);
	aux = 0;

	return node;
}

bool isEmptyQueue(struct Queue* queue){
	return queue -> head == NULL;
}


//stack functions
void pushStack(struct Stack *stack, struct TreeNode *root){
	(stack -> top)++;
	stack -> vect[stack -> top] = root;
}

void popStack(struct Stack *stack){
	stack -> vect[stack -> top] = 0;
	(stack -> top)--;
}

struct TreeNode* topStack(struct Stack *stack){
	return stack -> vect[stack -> top];
}

bool isEmptyStack(struct Stack stack){
	if(stack.top == -1)
		return true;

	return false;
}

void initStack(struct Stack *stack, int size){
	stack -> top = -1;
	stack -> vect = (struct TreeNode**)malloc(size * sizeof(struct TreeNode*));
}

void deleteNode(struct TreeNode *root){
	root -> val = 0;

	memset(root, 0, sizeof(struct TreeNode));
	free(root);
	root = 0;
}



//used the stack to keep track of the visited nodes
int *inorderTraversalIterative(struct TreeNode *root, int size){
	struct Stack *stack = 0;
	stack = (struct Stack*)malloc(sizeof(struct Stack));

	initStack(stack, size);

	struct TreeNode *help = root;
	int *answer = 0;
	int i = 0;

	answer = (int*)malloc(size * sizeof(int));
	
	pushStack(stack, help);

	while(help || !isEmptyStack(*stack)){
		
		while(help){
			pushStack(stack, help);
			help = help->left;
		}

		help = topStack(stack);
		popStack(stack);
		
		answer[i++] = help->val;
		help = help->right;
	}
	
	return answer;
}


//the problem wants you to return an array, made this function to see the results
void printArray(int *array, int size, FILE *out){

	if(!out){
		fprintf(stderr, "File didn't open correctly!\n");
		exit(EXIT_FAILURE);
	}

	fprintf(out,"Inorder traversal:");

	for(int i = 0; i < size; i++){
		fprintf(out, "%d ", array[i]);
	}

	fprintf(out, "\n");
}
