class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        vector<vector<int>> ref = matrix; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(ref[i][j] == 0){
                    for(int x = 0; x < m; x++){
                        matrix[x][j] = 0; 
                    }
                    for(int y = 0; y < n; y++){
                        matrix[i][y] = 0; 
                    }
                }
            }
        }
    }
};
