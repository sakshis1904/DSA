class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (int x : nums) {
            int n = res.size();
            for (int i = 0; i < n; i++) {
                auto temp = res[i];
                temp.push_back(x);
                res.push_back(temp);
            }
        }
        return res;
    }
};
