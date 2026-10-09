class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size(); 
        vector<string> res(n); 
        priority_queue<pair<int,int>> heap; 

        for(int i = 0; i < n; i++){
            heap.push({score[i] , i}); 
        }
        int rank = 1; 
        while(!heap.empty()){
            auto[val,index] = heap.top(); 
            heap.pop(); 
            if(rank == 1){
                res[index] = "Gold Medal"; 
            }
            else if(rank == 2){
                res[index] = "Silver Medal"; 
            }
            else if(rank == 3){
                res[index] = "Bronze Medal"; 
            }
            else{
                res[index] = to_string(rank);
            }
            rank++; 
        }
        return res;
    }
};
