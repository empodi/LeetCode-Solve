class Solution {
public:
    int len;
    void helper(vector<string>& p, string str, int left, int right) {
        
        if (left == len && right == len) {
            p.push_back(str);
            return;
        }
        if (left == right) {
            helper(p, str + "(", left + 1, right);
            return;
        }
        if (left < len)
            helper(p, str + "(", left + 1, right);
        if (right < len)
            helper(p, str + ")", left, right + 1);
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> p;
        string str = "(";
        len = n;
        
        helper(p, str, 1, 0);
        
        return p;
    }
};