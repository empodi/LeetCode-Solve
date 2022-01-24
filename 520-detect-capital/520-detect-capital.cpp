class Solution {
public:
    bool detectCapitalUse(string word) {
        
        bool allUpper, allDown, firstUpper, othersDown;
        allUpper = allDown = othersDown = true;
        firstUpper = false;
        
        for (int i = 0; i < word.length(); i++) {
            
            if (i == 0) {
                if (word[i] <= 'Z') firstUpper = true;
            }
            else {
                if (word[i] <= 'Z') othersDown = false;
            }
            
            if (word[i] <= 'Z') allDown = false;
            else allUpper = false;
            
        }
        
        return allUpper || allDown || (firstUpper && othersDown);
    }
};