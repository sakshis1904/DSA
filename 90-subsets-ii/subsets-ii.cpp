class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        int start = 0, end = 0;
        for (int i = 0; i < nums.size(); i++) {
            start = 0;
            if (i > 0 && nums[i] == nums[i-1]) start = end;
            end = res.size();
            for (int j = start; j < end; j++) {
                auto temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
};
