/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1; 
        ListNode* prev = nullptr; 
        int car = 0; 

        while(l1 != nullptr && l2 != nullptr){
            int sum = l1->val + l2->val + car; 
            l1->val = sum % 10; 
            car = sum / 10; 
            prev = l1; 
            l1 = l1->next; 
            l2 = l2->next; 
        }
        if(l2 != nullptr){
            prev->next = l2; 
            l1 = l2; 
        }
        while(l1 != nullptr && car != 0){
            int sum = l1->val + car; 
            l1->val = sum % 10; 
            car = sum / 10; 
            prev = l1; 
            l1 = l1->next; 
        }
        if(car != 0){
            prev->next = new ListNode(car); 
        }
        return head;
    }
};
