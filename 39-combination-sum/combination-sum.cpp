class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    void backtrack(int i, vector<int>& candidates, int target) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (i >= candidates.size() || target < 0) return;

        temp.push_back(candidates[i]);
        backtrack(i, candidates, target - candidates[i]);
        temp.pop_back();

        backtrack(i + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(0, candidates, target);
        return res;
    }
};

