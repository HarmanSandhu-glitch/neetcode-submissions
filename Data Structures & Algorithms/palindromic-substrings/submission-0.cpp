class Solution {
public:
    bool isPalindrome(string s) {
        string o = s;
        reverse(s.begin(), s.end());
        return o == s;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int answer = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // substr(start, length)
                if (isPalindrome(s.substr(i, j - i + 1))) {
                    answer++;
                }
            }
        }

        return answer;
    }
};