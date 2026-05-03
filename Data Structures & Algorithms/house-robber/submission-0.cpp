class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[1] = nums[0];
        for(int i = 2;i <= n;i++){
            int pickCur = nums[i-1] + dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pickCur,notPick);
        }
        return dp[n];
    }
};
