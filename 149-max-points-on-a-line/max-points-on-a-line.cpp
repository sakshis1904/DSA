class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<long long, int> mp;
            int same = 1, curMax = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    same++;
                    continue;
                }

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = 1;
                }

                long long key = ((long long)dx << 32) ^ (unsigned long long)(dy);
                curMax = max(curMax, ++mp[key]);
            }

            ans = max(ans, curMax + same);
        }
        return ans;
    }
};
