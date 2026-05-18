class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& stoneValue, int index) {
        if (index >= stoneValue.size()) {
            return 0;
        }

        if (dp[index] != INT_MIN) {
            return dp[index];
        }

        int sum = 0;
        int ans = INT_MIN;

        for (int i = 0; i < 3 && index + i < stoneValue.size(); i++) {
            sum += stoneValue[index + i];

            ans = max(ans,
                      sum - solve(stoneValue, index + i + 1));
        }

        return dp[index] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        dp.resize(n, INT_MIN);

        int diff = solve(stoneValue, 0);

        if (diff > 0) {
            return "Alice";
        } 
        else if (diff < 0) {
            return "Bob";
        }

        return "Tie";
    }
};