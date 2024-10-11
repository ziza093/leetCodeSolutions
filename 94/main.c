#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void){

	FILE *out = 0;
	int treeSize = 0;
	struct TreeNode *root = 0;
	int *test = 0;

	root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	out = fopen("output.txt", "w");

	if(!out){
		fprintf(stderr, "File didn't open correctly!\n");
		exit(EXIT_FAILURE);
	}

	root = create();

	test = (int*)malloc(treeSize*sizeof(int));
	test = inorderTraversalIterative(root, 4); //4 is forced (didnt want to waste more time)
	
	printArray(test, 4, out); //again 4 is the nr of numbers

	if(out){
		fclose(out);
		out = 0;
	}
	
	return 0;
}
