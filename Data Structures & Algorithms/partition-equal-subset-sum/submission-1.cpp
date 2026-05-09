class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int tSum = accumulate(nums.begin(), nums.end(), 0) ;
        if(tSum % 2 != 0) return false;
        int target = tSum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        // dp[0][0] = true;
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;  // always possible to reach 0 by taking none
        }
        for (int i = 1; i <= n; i++) {
            for (int t = 0; t <= target; t++) {
                // skip
                dp[i][t] =  dp[i - 1][t];
                // taking
                if (nums[i - 1] <= t) {
                    dp[i][t] = dp[i][t] || dp[i - 1][t - nums[i - 1]];
                }
            }
        }
        return dp[n][target];
    }
};
