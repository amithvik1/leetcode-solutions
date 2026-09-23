class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals){
        int res = 0;
        auto isOverlap = [&](int i, int j) -> bool{
            int mnmx = min(intervals[i][1],intervals[j][1]); 
            int mxmn = max(intervals[i][0],intervals[j][0]); 
            return (mxmn <= mnmx);
        }; 
        for(int i = 0; i < intervals.size(); i++){
            for(int j = i+1; j < intervals.size(); j++){
                if(isOverlap(i,j)) res++; 
            }
        }
        return res;
    }
};
