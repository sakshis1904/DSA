class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int idx, int target, vector<int>& a) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = idx; i < a.size(); i++) {
            if (i > idx && a[i] == a[i - 1]) continue;
            if (a[i] > target) break;
            path.push_back(a[i]);
            dfs(i + 1, target - a[i], a);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, target, candidates);
        return res;
    }
};
