class Solution {
private:
    void fun(string& s) {
        vector<pair<int,int>> val;
        for (auto ch : s)
            if (val.empty() or val.back().second != ch - '0')
                val.push_back({1,ch - '0'});
            else
                ++val.back().first;
        s.clear();
        for (auto [x, y] : val) 
            s += to_string(x), s += char(y + '0');
    }
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n) 
            fun(s);
        return s;
    }
};