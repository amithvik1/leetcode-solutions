class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }
        ListNode* temp = head;
        ListNode* temp2 = head;  
        vector<int> res = {-1,-1}; 
        int crit = 0; 
        int count = 0; 
        while(temp2 != nullptr){
            temp2 = temp2->next; 
            count++; 
        }
        vector<int> arr (count , 0); 
        int k = 1; 
        while(temp->next->next != nullptr){
            if((temp->val < temp->next->val && temp->next->next->val < temp->next->val) || 
               (temp->val > temp->next->val && temp->next->next->val > temp->next->val)){
                arr[k] = 1;
            }
            k++; 
            temp = temp->next; 
        }
        int mindistance = INT_MAX; 
        int maxdistance = -1; 
        int i = 0; 
        int j = arr.size()-1; 
        while(i < arr.size() && arr[i] != 1){
            i++; 
        }
        if(i == arr.size()) return res; 
    
        while(arr[j] != 1 && j > i){
            j--; 
        }
        if(i == j) return res;
        maxdistance = j-i;  
        
        int previ = i;
        for(int l = i + 1; l <= j; l++){
            if(arr[l] == 1) {
                mindistance = min(mindistance, l - previ);
                previ = l; 
            }
        }
        res[0] = mindistance;
        res[1] = maxdistance;
        return res;
    }
};

