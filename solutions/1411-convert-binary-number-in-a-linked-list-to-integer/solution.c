/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    int sum = 0;
    struct ListNode* p = head;
    while (p != NULL) {
        sum = (sum * 2) + p->val; 
        p = p->next;
    }
    return sum;
}

