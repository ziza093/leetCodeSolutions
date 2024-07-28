#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main(void){

    struct ListNode* head = 0;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));

    createList(&head);

    printList(head);
    
    head = deleteDuplicates(head);

    printList(head);

    return 0;
}
