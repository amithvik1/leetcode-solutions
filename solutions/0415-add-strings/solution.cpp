class Solution {
public:
    string addStrings(string num1, string num2) {
        int s1 = num1.length() - 1; 
        int s2 = num2.length() - 1; 
        int car = 0; 
        string res =  ""; 
        while(s1 >= 0 || s2 >= 0 || car > 0){
            int sum = car; 
            if(s1 >= 0){
                sum += num1[s1] - '0'; 
                s1--; 
            }
            if(s2 >= 0){
                sum += num2[s2] - '0'; 
                s2--; 
            }
        
            car = sum / 10; 
            sum = sum % 10; 
            
            res.push_back(sum + '0'); 
        }
        reverse(res.begin(), res.end()) ;
        return res;
    }
};
