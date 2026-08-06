class Solution {
public:

    void solve(int node, vector<vector<int>>& nums, vector<bool>& visited) {
        visited[node] = true;
        for(int x : nums[node]) {
            if(!visited[x]) {
                solve(x, nums, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);

        solve(0, rooms, visited);

        for(bool x : visited) if(!x) return false;
        return true;
    }
};