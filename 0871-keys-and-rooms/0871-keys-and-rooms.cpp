class Solution {
private:
    int dfs(int src, vector<vector<int>>& toList, vector<bool>& vis) {
        int ans = 1;
        vis[src] = true;
        for (auto& nbr : toList[src])
            if (!vis[nbr])
                ans += dfs(nbr, toList, vis);
        return ans;
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis (rooms.size(), false);
        return dfs(0, rooms, vis) == rooms.size();
    }
};