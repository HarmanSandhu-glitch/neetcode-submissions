class Solution {
public:
    void help(vector<int> &nums,int n,vector<int> &path,vector<vector<int>> &answer){
        if(n == nums.size()){
            answer.push_back(path);
            return;
        }
        // take
        path.push_back(nums[n]);
        help(nums,n+1,path,answer);
        path.pop_back();
        help(nums,n+1,path,answer);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> path;
        help(nums,0,path,answer);
        return answer;
    }
};
