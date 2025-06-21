class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto& ch : s) 
            switch (ch) {
            
            case '(':
            case '{':
            case '[':
                stk.push(ch);
                break;
            
            case ')':
                if (!stk.empty() and stk.top() == '(')
                    stk.pop();
                else
                    return false;
                break;
            
            case '}':
                if (!stk.empty() and stk.top() == '{')
                    stk.pop();
                else
                    return false;
                break;
            
            case ']':
                if (!stk.empty() and stk.top() == '[')
                    stk.pop();
                else
                    return false;
                break;
            
            default:
                return false;
            }
        return stk.empty();
    }
};