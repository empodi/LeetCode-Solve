class Solution {
public:
    int len;
    void helper(vector<string>& p, string& str, int left, int right) {
        
        if (left == len && right == len) {
            p.push_back(str);
            return;
        }
        if (left == right) {
            str += "(";
            helper(p, str, left + 1, right);
            str.pop_back();
            return;
        }
        if (left < len) {
            str += "(";
            helper(p, str, left + 1, right);
            str.pop_back();
        }
        if (right < len) {
            str += ")";
            helper(p, str, left, right + 1);
            str.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> p;
        string str = "(";
        len = n;
        
        helper(p, str, 1, 0);
        
        return p;
    }
};