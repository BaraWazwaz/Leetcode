class Solution {
private:
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> ans;
    pair<int, int> getFurthest(int src, int depth) {
        pair<int, int> ans = {src, depth};
        vis[src] = true;
        for (auto& nbr : adj[src])
            if (!vis[nbr]) {
                auto temp = getFurthest(nbr, depth + 1);
                if (temp.second > ans.second)
                    ans = temp;
            }
        return ans;
    }
    void yoink(int src) {
        ans.clear();
        vis.assign(adj.size(), false);

        vector<int> pre (adj.size(), -1);
        queue<int> q;
        q.push(src);
        vis[src] = true;

        int last = src;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            for (auto& y : adj[x])
                if (!vis[y]) {
                    pre[y] = x;
                    vis[y] = true;
                    q.push(y);
                }
            last = x;
        }
        vector<int> path = { last };
        int cur = last;
        while (pre[cur] != -1) {
            cur = pre[cur];
            path.push_back(cur);
        }
        if (path.size() % 2 == 0)
            ans.push_back(path[path.size() / 2 - 1]);
        ans.push_back(path[path.size() / 2]);
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 2) {
            vector<int> ans (n);
            iota(ans.begin(), ans.end(), 0ll);
            return ans;
        }
        adj.assign(n, {});
        vis.assign(n, false);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        auto a = getFurthest(0, 0);
        yoink(a.first);
        return ans;
    }
};