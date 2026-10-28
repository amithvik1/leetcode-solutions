class Solution {
public:
    void dfs(int curr , vector<vector<int>>& rooms, vector<bool>& visit){
        visit[curr] = true; 
        for(int key : rooms[curr]){
            if(!visit[key]){
                dfs(key, rooms , visit);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visit(n,false); 
        dfs(0,rooms,visit);
        for(bool x : visit){
            if(x == false) return false;
        }
        return true;
    }
};
