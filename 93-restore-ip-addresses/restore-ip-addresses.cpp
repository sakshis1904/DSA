class Solution {
public:
    vector<string> res;

    void dfs(string &s, int idx, int part, string cur) {
        if (part == 4 && idx == s.size()) {
            cur.pop_back();
            res.push_back(cur);
            return;
        }
        if (part == 4 || idx == s.size()) return;

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string t = s.substr(idx, len);
            if ((t[0] == '0' && t.size() > 1) || stoi(t) > 255) continue;
            dfs(s, idx + len, part + 1, cur + t + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return res;
    }
};
