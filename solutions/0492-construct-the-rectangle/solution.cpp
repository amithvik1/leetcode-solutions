class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width = static_cast<int>(sqrt(area)); 
        vector<int> res = {area , 1}; 
        while(area % width != 0){
            width--; 
        } 
        return {area / width, width};
    }
};
