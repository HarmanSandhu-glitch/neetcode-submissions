class Solution {
public:
    int combinationSum4(int target) {
        vector<int> dp(target + 1, INT_MAX);

        dp[0] = 0;

        for (int t = 1; t <= target; t++) {
            int i = 1;

            while ((i * i) <= t) {
                dp[t] = min(dp[t], 1 + dp[t - (i * i)]);
                i++;
            }
        }

        return dp[target];
    }

    int numSquares(int n) {
        return combinationSum4(n);
    }
};