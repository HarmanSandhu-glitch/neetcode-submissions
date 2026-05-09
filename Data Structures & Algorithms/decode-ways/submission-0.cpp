class Solution {
public:
    vector<int> dp;

    int solve(string &s, int index) {
        if (index == s.size()) {
            return 1;
        }
        if (s[index] == '0') {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int ways = solve(s, index + 1);
        if (index + 1 < s.size()) {
            int num = (s[index] - '0') * 10 + (s[index + 1] - '0');
            if (num >= 10 && num <= 26) {
                ways += solve(s, index + 2);
            }
        }

        return dp[index] = ways;
    }

    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        dp.resize(s.size(), -1);

        return solve(s, 0);
    }
};