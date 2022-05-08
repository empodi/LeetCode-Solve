/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> flattened;
    int flattenedSize = 0;
    int curIdx = 0;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        
        solve(nestedList);
        flattenedSize = flattened.size();
    }
    
    void solve(vector<NestedInteger> &nestedList) {
        
        int curLen = nestedList.size();

        for (int i = 0; i < curLen; i++) {
            
            if (nestedList[i].isInteger()) {
                flattened.push_back(nestedList[i].getInteger());
            }
            else {
                solve(nestedList[i].getList());
            }
        }        
    }
    
    int next() {
        
        if (hasNext()) {
            return flattened[curIdx++];
        }
        return INT_MIN;
    }
    
    bool hasNext() {
        
        if (curIdx < flattenedSize) 
            return true;
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */