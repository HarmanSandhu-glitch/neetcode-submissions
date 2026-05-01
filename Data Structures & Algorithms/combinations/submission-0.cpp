class Solution {
public:
    vector<vector<int>> answer;
    vector<int> path;
    void help(int n,int k,int curNum=1){
        if(k == 0){
            answer.push_back(path);
            return;
        }
        if(curNum > n){
            return;
        }
        path.push_back(curNum);
        help(n,k-1,curNum+1);
        path.pop_back();
        help(n,k,curNum+1);
    }
    vector<vector<int>> combine(int n, int k) {
        help(n,k);
        return answer;
    }
};