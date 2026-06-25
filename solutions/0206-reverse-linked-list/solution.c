/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL; 
    struct ListNode* curr = head; 
    while(curr != NULL){
        struct ListNode* nextnode = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = nextnode;
    }
    return prev;
}
