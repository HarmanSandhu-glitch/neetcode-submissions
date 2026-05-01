class Solution {
public:
    vector<int> visited;
    vector<vector<int>> answer;
    vector<int> path;
    void help(vector<int> nums,int index){
        if(index == nums.size()){
            answer.push_back(path);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(visited[i]){
                continue;
            }
            visited[i]  = true;
            path.push_back(nums[i]);;
            help(nums,index+1);
            path.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();
        visited.assign(n,0);
        help(nums,0);
        return answer;
    }
};
