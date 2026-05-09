class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxPro(n, INT_MIN), minPro(n, INT_MAX);

        maxPro[0] = nums[0];
        minPro[0] = nums[0];

        int ans = nums[0];

        for (int i = 1; i < n; i++) {

            int newPro1 = minPro[i - 1] * nums[i];
            int newPro2 = maxPro[i - 1] * nums[i];

            maxPro[i] = max({nums[i], newPro1, newPro2});
            minPro[i] = min({nums[i], newPro1, newPro2});

            ans = max(ans, maxPro[i]);
        }

        return ans;
    }
};