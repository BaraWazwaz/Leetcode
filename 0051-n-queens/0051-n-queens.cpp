class Solution {
private:
    int n;
    int cnt;
    vector<vector<string>> ans;
    vector<string> current;
    vector<bool> row, col, d1, d2;
    void recur(int i, int j) {
        if (i == n) {
            if (cnt == n)
                ans.push_back(current);
            return;
        }
        if (
            !row[i] &&
            !col[j] &&
            !d1[i - j + n] &&
            !d2[i + j]
        ) {
            ++cnt;
            current[i][j] = 'Q';
            row[i] = true;
            col[j] = true;
            d1[i - j + n] = true;
            d2[i + j] = true;
            if (j == n - 1)
                recur(i + 1, 0);
            else
                recur(i, j + 1);
            --cnt;
            current[i][j] = '.';
            row[i] = false;
            col[j] = false;
            d1[i - j + n] = false;
            d2[i + j] = false;
        }
        if (j == n - 1)
            recur(i + 1, 0);
        else
            recur(i, j + 1);
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        cnt = 0;
        ans = {};
        current = vector(n, string(n, '.'));
        row = vector(n, false);
        col = vector(n, false);
        d1 = vector(2 * n - 1, false);
        d2 = vector(2 * n - 1, false);
        recur(0, 0);
        return ans;
    }
};