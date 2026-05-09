class Solution {
public:
    int inf = 1e9;

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, inf));

        // 0 coins needed to make amount 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {

                // Don't take coin
                dp[i][j] = dp[i - 1][j];

                // Take coin
                if (j >= coins[i - 1]) {
                    dp[i][j] = min(
                        dp[i][j],
                        1 + dp[i][j - coins[i - 1]]
                    );
                }
            }
        }

        return dp[n][amount] == inf ? -1 : dp[n][amount];
    }
};