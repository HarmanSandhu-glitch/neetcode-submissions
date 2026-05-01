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
            help(nums,target-nums[index],index+1,path);
            path.pop_back();
        }
        // Skip logic to avoid TLE: skip duplicates if we didn't take the current element
        int nextIndex = index + 1;
        while (nextIndex < nums.size() && nums[nextIndex] == nums[index]) nextIndex++;
        help(nums,target,nextIndex,path);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> fAnswer;
        vector<int> path;
        help(nums,target,0,path);
        for(auto i : answer){
            fAnswer.push_back(i);
        }
        return fAnswer;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        return combinationSum(candidates,target);
    }
};
