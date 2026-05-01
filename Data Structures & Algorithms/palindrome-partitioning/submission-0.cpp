class Solution {
public:
    bool isPalindrome(string s, int startIndex, int endIndex){
        string oriString = s.substr(startIndex, endIndex - startIndex + 1);
        string oriBackup = oriString;
        reverse(oriString.begin(), oriString.end());
        return oriString == oriBackup;
    }
    vector<vector<string>> answer;
    void help(vector<string> &path,int startIndex,string s){
        if(startIndex >= s.size()){
            answer.push_back(path);
            return;
        }
        for(int i = startIndex;i < s.size();i++){
            if(isPalindrome(s,startIndex,i)){
                path.push_back(s.substr(startIndex,i-startIndex+1));
                help(path,i+1,s);
                path.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        help(path,0,s);
        return answer;
    }
};
