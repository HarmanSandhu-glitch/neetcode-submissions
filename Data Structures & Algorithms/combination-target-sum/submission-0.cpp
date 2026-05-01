class Solution {
public:
    set<vector<int>> answer;
    void help(vector<int> &nums,int target,int index,vector<int> &path){
        if(target == 0){
            answer.insert(path);
            return;
        }
        if(index == nums.size()){
            return;
        }
        // take
        if(nums[index] <= target){
            path.push_back(nums[index]);
            help(nums,target-nums[index],index,path);
            path.pop_back();
        }
        help(nums,target,index+1,path);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> fAnswer;
        vector<int> path;
        help(nums,target,0,path);
        for(auto i : answer){
            fAnswer.push_back(i);
        }
        return fAnswer;
    }
};
