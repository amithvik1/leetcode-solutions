class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int count = 0; 
        int size = s.size(); 
        int pize = p.size(); 

        vector<int> s1 (26,0); 
        vector<int> p1 (26,0); 
        vector<int> res; 
        if(pize > size) return res; 

        for(int i = 0; i < pize; i++){
            s1[s[i] - 'a']++; 
            p1[p[i] - 'a']++; 
        }
        if(s1 == p1){
            res.push_back(0); 
        }
        for(int i = pize; i < size; i++){
            s1[s[i] - 'a']++; 
            s1[s[i-pize] - 'a']--; 
            if(s1 == p1){
                res.push_back(i-pize+1);
            }
        }
        return res; 
    }
};
