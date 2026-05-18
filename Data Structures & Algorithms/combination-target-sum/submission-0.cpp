class Solution {
public:
    vector<vector<int>> ans;
    void dfs(const vector<int>& nums, int lastIndex, int target, vector<int> v){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        int n = nums.size();
        for(int i=lastIndex;i<n;i++){
            if(target >= nums[i]){
                v.push_back(nums[i]);
                dfs(nums, i, target - nums[i], v);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        ans.clear();
        dfs(nums, 0, target, {});
        return ans;
    }
};
