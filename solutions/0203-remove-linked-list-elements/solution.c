/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int target) {
    while(head != NULL && head->val == target){
        struct ListNode* temp = head->next; 
        free(head); 
        head = temp; 
    }
    if(head == NULL) return NULL; 
    struct ListNode* curr = head; 
    while(curr->next != NULL){
        if(curr->next->val == target){
            struct ListNode* todelete = curr->next; 
            curr->next = curr->next->next; 
            free(todelete); 
        }
        else{
            curr = curr->next; 
        }
    }
    return head; 
}

