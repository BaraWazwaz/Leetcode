class Solution {
    string cur;
    vector<string> v;
    void recur(int open, int close) {
        if (!open && !close)
            return v.push_back(cur);
        if (open) {
            cur.push_back('(');
            recur(open - 1, close);
            cur.pop_back();
        }
        if (open < close) {
            cur.push_back(')');
            recur(open, close - 1);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        cur = "";
        cur.reserve(2 * n);
        v.clear();
        recur(n, n);
        return v;
    }
};