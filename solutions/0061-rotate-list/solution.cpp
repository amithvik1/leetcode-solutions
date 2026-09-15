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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr; 
        int length = 1; 
        ListNode* p = head; 
        while(p->next != nullptr){
            p = p->next; 
            length++; 
        }
        p->next = head; 
        int x = length - (k % length); 
        while(x != 0){
            p = p->next; 
            x--; 
        }
        ListNode* temp = p->next;
        p->next = nullptr;   
        return temp; 
    }
};
