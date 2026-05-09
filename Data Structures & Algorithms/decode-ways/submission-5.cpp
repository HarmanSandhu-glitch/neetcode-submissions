class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if (n == 0 || s[0] == '0') {
            return 0;
        }

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            char prevEle = s[i - 2];
            char curEle = s[i - 1];

            // Single digit decode
            if (curEle != '0') {
                dp[i] += dp[i - 1];
            }

            // Two digit decode
            int num = (prevEle - '0') * 10 + (curEle - '0');

            if (num >= 10 && num <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};