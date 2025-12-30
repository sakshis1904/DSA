class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix[0].size(), ans = 0;
        vector<int> heights(n, 0);
        for (auto& row : matrix) {
            for (int i = 0; i < n; i++)
                heights[i] = row[i] == '1' ? heights[i] + 1 : 0;
            stack<int> st;
            for (int i = 0; i <= n; i++) {
                int h = (i == n ? 0 : heights[i]);
                while (!st.empty() && h < heights[st.top()]) {
                    int height = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? i : i - st.top() - 1;
                    ans = max(ans, height * width);
                }
                st.push(i);
            }
        }
        return ans;
    }
};
