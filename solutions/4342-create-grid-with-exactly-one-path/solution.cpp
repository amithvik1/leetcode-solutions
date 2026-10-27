class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string a(n , '.'); 
        string b(n-1 , '#'); 
        vector<string> res;
        res.push_back(a);  
        b.push_back('.');
        for(int i = 0; i < m-1; i++){
            res.push_back(b); 
        }
        return res;
    }
};
