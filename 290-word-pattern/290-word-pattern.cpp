class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> v;
        unordered_map<string, char> hash;
        
        istringstream ss(s);
        string stringBuffer;
        while (getline(ss, stringBuffer, ' '))
            v.push_back(stringBuffer);
        
        if (pattern.length() != v.size()) return false;
        
        for (int i = 0; i < v.size(); i++) {
            
            if(hash.count(v[i]) == 0) {
                
                for (auto& elem : hash)
                    if (elem.second == pattern[i]) return false;
                        
                hash.insert({v[i], pattern[i]});
            }
            else {
                if (hash[v[i]] != pattern[i]) return false;
            }
        }
        
        return true;
    }
};