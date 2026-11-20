class Solution {
private:
    int sz;
    vector<string> ans;
    string current;
    void recur(int i, int o, int c) {
        if (i == 2 * sz) {
            ans.push_back(current);
            return;
        }
        if (o < sz) {
            current.push_back('(');
            recur(i + 1, o + 1, c);
            current.pop_back();
        }
        if (c < o && c < sz) {
            current.push_back(')');
            recur(i + 1, o, c + 1);
            current.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        sz = n;
        ans = {};
        current = ""; current.reserve(2 * sz);
        recur(0, 0, 0);
        return ans;
    }
};