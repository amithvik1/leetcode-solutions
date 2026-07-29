class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> m = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
            {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
            {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
        };

        int first = date.find(' ');

        string day = (first == 4) ? date.substr(0, 2) : "0" + date.substr(0, 1);

        string month = m[date.substr(first + 1 , 3)]; 
         
        string year = date.substr(date.find(' ', first + 1) + 1); 


        return year + "-" + month + "-" + day;
    }
};
