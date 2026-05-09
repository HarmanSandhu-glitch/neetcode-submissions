class Solution {
public:
    set<string> words;
    vector<int> dp;
    bool help(int index, string s) {
        if (index == s.size()) {
            return true;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        bool partition = false;

        for (int i = index; i < s.size(); i++) {

            string sub = s.substr(index, i - index + 1);

            if (words.count(sub)) { // i can choose to partition here
                partition = partition || help(i + 1, s);
            }
        }

        return dp[index] = partition;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        for (auto i : wordDict) {
            words.insert(i);
        }
        dp.assign(s.size(),-1);

        return help(0, s);
    }
};