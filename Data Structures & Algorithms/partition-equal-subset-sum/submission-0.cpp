class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // If total sum is odd, cannot partition equally
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Sum 0 is always possible
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int t = 1; t <= target; t++) {

                // Skip current element
                dp[i][t] = dp[i - 1][t];

                // Take current element
                if (nums[i - 1] <= t) {
                    dp[i][t] = dp[i][t] || dp[i - 1][t - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};