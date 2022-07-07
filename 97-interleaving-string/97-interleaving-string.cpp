class Solution {
private:
    int memo[102][102];
    bool solve(string& a, string& b, string& t, int aIdx, int bIdx, int tIdx) {
        if (aIdx == a.length() && bIdx == b.length() && tIdx == t.length())
            return true;
        if (memo[aIdx][bIdx] > -1) return memo[aIdx][bIdx];
        
        memo[aIdx][bIdx] = false;
        if (aIdx < a.length() && a[aIdx] == t[tIdx]) 
            memo[aIdx][bIdx] |= solve(a, b, t, aIdx + 1, bIdx, tIdx + 1);
        if (bIdx < b.length() && b[bIdx] == t[tIdx])
            memo[aIdx][bIdx] |= solve(a, b, t, aIdx, bIdx + 1, tIdx + 1);
        return memo[aIdx][bIdx];
    }
public:
    bool isInterleave(string a, string b, string t) {
        memset(memo, -1, sizeof(memo));
        return solve(a,b,t,0,0,0);
    }
};