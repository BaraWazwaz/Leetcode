class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> preList (numCourses), postList (numCourses);
        vector<bool> vis (numCourses, false);
        queue<int> q;
        
        for (auto edge : prerequisites) {
            int a = edge[0], b = edge[1];
            preList[b].insert(a);
            postList[a].insert(b);
        }
        for (int i = 0; i < numCourses; ++i)
            if (preList[i].empty())
                q.push(i);
        
        while (!q.empty()) {

            auto task = q.front();
            q.pop();
            vis[task] = true;

            for (auto unlocked : postList[task]) {
                preList[unlocked].erase(task);
                if (preList[unlocked].empty())
                    q.push(unlocked);
            }
        }

        return accumulate(vis.begin(), vis.end(), true, logical_and());
    }
};