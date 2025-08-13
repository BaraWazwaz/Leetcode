class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> preList (numCourses), postList (numCourses);
        queue<int> q;
        
        for (auto edge : prerequisites) {
            int a = edge[0], b = edge[1];
            preList[a].insert(b);
            postList[b].insert(a);
        }
        for (int i = 0; i < numCourses; ++i)
            if (preList[i].empty())
                q.push(i);
        
        vector<int> ans;
        ans.reserve(numCourses);
        while (!q.empty()) {

            auto task = q.front();
            q.pop();
            ans.push_back(task);

            for (auto unlocked : postList[task]) {
                preList[unlocked].erase(task);
                if (preList[unlocked].empty())
                    q.push(unlocked);
            }
        }

        if (ans.size() != numCourses)
            ans.clear();

        return ans;
    }
};