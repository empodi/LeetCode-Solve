class Solution {
private:
    void solve(vector<string>& v, string str, int left, int right) {
        if (left < 0 || right < 0) return;
        if (left == 0 && right == 0) {
            v.push_back(str);
            return;
        } 
        if (left == right) {
            str += "(";
            solve(v, str, left - 1, right);
        }
        else {
            str += "(";
            solve(v, str, left - 1, right);
            str.pop_back();
            str += ")";
            solve(v, str, left, right - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string str = "(";
        solve(v, str, n - 1, n);
        return v;
    }
};