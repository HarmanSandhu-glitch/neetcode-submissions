class Solution {
public:
    bool isPalindrome(string s) {
        string o = s;
        reverse(s.begin(), s.end());
        return o == s;
    }

    // int countSubstrings(string s) {
    //     int n = s.size();
    //     int answer = 0;
    //     vector<vector<bool>> dp(n,vector<bool>(n,false));
    //     for(int i = n-1;i >= 0;i--){
    //         for(int j = i;j < n;j++){
    //             if(s[i] == s[j] && ((j-i) <= 2 || dp[i+1][j-1]) ){
    //                 dp[i][j] = true;
    //                 answer++;
    //             }
    //         }
    //     }

    //     return answer;
    // }
  int n;
vector<vector<int>> dp;

int help(int i, int j, string &s) {
    if (i >= n || j < 0 || i > j) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (s[i] == s[j] && ((j - i) <= 2 || help(i + 1, j - 1, s))) {
        return dp[i][j] = 1;
    }

    return dp[i][j] = 0;
}

int countSubstrings(string s) {
    n = s.size();
    int answer = 0;

    dp.assign(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            answer += help(i, j, s);
        }
    }

    return answer;
}
};