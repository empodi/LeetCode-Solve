class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int answer = 0;
        
        for (int i = 0; i < heights.size(); i++)
        {
            while (stk.size() && heights[stk.top()] > heights[i])
            {
                int top = stk.top();
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                int area = heights[top] * width;
                answer = max(answer, area);
            }
            stk.push(i);
        }
        while (stk.size())
        {
            int top = stk.top(); 
            stk.pop();
            int width = stk.empty() ? heights.size() : heights.size() - stk.top() - 1; 
            int area = heights[top] * width;
            answer = max(answer, area);
        }
        return answer;
    }
};