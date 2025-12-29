class Solution {
public:
    unordered_set<string> st;
    unordered_map<string, vector<string>> dp;

    vector<string> solve(string s) {
        if (dp.count(s)) return dp[s];
        vector<string> res;
        for (int i = 1; i <= s.size(); i++) {
            string left = s.substr(0, i);
            if (st.count(left)) {
                if (i == s.size()) res.push_back(left);
                else {
                    vector<string> right = solve(s.substr(i));
                    for (auto &r : right)
                        res.push_back(left + " " + r);
                }
            }
        }
        return dp[s] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto &w : wordDict) st.insert(w);
        return solve(s);
    }
};
