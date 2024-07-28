#ifndef HEADER_H_
#define HEADER_H_

struct ListNode{

    int val;
    struct ListNode* next;
};

void createList(struct ListNode** head);
void insertList(struct ListNode** head, int value);
void printList(struct ListNode* head);

struct ListNode* deleteDuplicates(struct ListNode* head);

#endif
