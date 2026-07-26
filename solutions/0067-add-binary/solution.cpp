class Solution {
public:
    string addBinary(string a, string b) {
        int p = a.size() -1; 
        int q = b.size() -1; 
        int carry = 0; 
        string res = ""; 

        while(p >= 0 || q >= 0 || carry > 0){
            int ones = 0; 

            if(p >= 0){
                if(a[p] == '1'){
                    ones++; 
                }
                p--; 
            }

            if(q >= 0){
                if(b[q] == '1'){
                    ones++; 
                }
                q--; 
            }

            if(carry){
                ones++; 
            }

            res.push_back((ones % 2) == 1 ? '1' : '0'); 
            carry = ones / 2;
        }
        reverse(res.begin(), res.end()); 
        return res; 
    }
};
