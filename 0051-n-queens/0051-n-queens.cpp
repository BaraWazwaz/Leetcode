class Solution {
private:

    // movement and bounds
    bool bounded(int x, int y, int n) {
        return 0 <= x && x < n && 0 <= y && y < n;
    }
    static constexpr int dx[8] = { +1, +0, -1, +0, +1, -1, -1, +1 };
    static constexpr int dy[8] = { +0, +1, +0, -1, +1, +1, -1, -1 };

    // data structures
    vector<vector<string>> total;
    vector<string> current;
    set<pair<int,int>> usableIndices;

    // recursion function
    void recur(int countPlaced) {
        int n = current.size();

        // base statement
        if (usableIndices.empty()) {
            if (countPlaced == n)
                total.push_back(current);
            return;
        }

        // loop over possible squares
        auto copy = usableIndices;
        vector<pair<int,int>> dontUse;
        for (auto& [x, y] : copy) {
            vector<pair<int,int>> removed;
            usableIndices.erase({x, y});
            dontUse.push_back({x, y});
            for (int dir = 0; dir < 8; ++dir) {
                for (int mag = 1; mag < n; ++mag) {
                    int xi = x + dx[dir] * mag;
                    int yi = y + dy[dir] * mag;
                    if (bounded(xi, yi, n)) {
                        auto it = usableIndices.find({xi, yi});
                        if (it != usableIndices.end()) {
                            usableIndices.erase(it);
                            removed.push_back({xi, yi});
                        }
                    }
                    else
                        break;
                }
            }
            current[x][y] = 'Q';
            recur(countPlaced + 1);
            for (auto& [xi, yi] : removed)
                usableIndices.insert({xi, yi});
            current[x][y] = '.';
        }
        for (auto& [x, y] : dontUse)
            usableIndices.insert({x, y});
    }

public:

    // master method
    vector<vector<string>> solveNQueens(int n) {
        total.clear();
        current.assign(n, string(n, '.'));
        usableIndices.clear();
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y)
                usableIndices.insert({x, y});
        recur(0);
        return total;
    }
};