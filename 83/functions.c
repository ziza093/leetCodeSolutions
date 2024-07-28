#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void createList(struct ListNode** head){

    FILE* input = 0;
    int n = 0;

    input = fopen("input.txt", "r");

    if(!input){
        fprintf(stderr, "File did not open succesfully! The program will now exit.\n");
        exit(EXIT_FAILURE);
    }

    while(fscanf(input, "%d", &n) == 1){
        insertList(head, n);
    }


    if(input){
        fclose(input);
        input = 0;
    }

}

void insertList(struct ListNode** head, int value){

    struct ListNode* aux = 0;
    aux = (struct ListNode*)malloc(sizeof(struct ListNode));

    aux->next = 0;
    aux->val = value;

    if(!*head){
        *head = aux;
    }
    else{
        struct ListNode* temp = *head;
        
        while(temp->next){
            temp = temp->next;
        }
        temp->next = aux;
    }
}


void printList(struct ListNode* head){
  
    FILE* out = 0;

    out = fopen("output.txt", "w");

    if(!head){
        printf("The list is empty!\n");
        return;
    }
    else if(!head->next){
        fprintf(out, "%d ", head->val);
        return;
    }

    while(head->next){
        fprintf(out, "%d ", head->val);
        head = head->next; 
    }

    fprintf(out, "%d\n", head->val);
    
    if(out){
        fclose(out);
        out = 0;
    }

}


struct ListNode* deleteDuplicates(struct ListNode* head){
   
    struct ListNode* help = head;

    if(head){
        while(head->next){
            if(head->val == head->next->val){
                struct ListNode* temp = head->next;
                head->next = head->next->next;
                
                memset(temp, 0, sizeof(struct ListNode));
                free(temp);
                temp = 0;
            }
            else{
                head = head->next;
            }
        }
    
    }

    return help;
}
