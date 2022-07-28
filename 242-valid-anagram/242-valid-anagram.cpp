#define LEN 26
class Solution {
private:
    bool check_identical(vector<int>& sv, vector<int>& tv) {
        for (int i = 0; i < LEN; i++) {
            if (sv[i] != tv[i]) return false;
        }
        return true;
    }
public:
    bool isAnagram(string s, string t) {
        vector<int> sv(LEN, 0), tv(LEN, 0);
        for (auto& c : s) sv[c - 'a']++;
        for (auto& c : t) tv[c - 'a']++;
        return check_identical(sv, tv);
    }
};