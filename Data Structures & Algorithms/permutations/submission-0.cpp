class Solution {
public:
    vector<vector<int>> ans;
    void findPermutation(const vector<int>& nums, vector<int> v, set<int> used){
        int n = nums.size();
        if((int)v.size() == n){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(used.find(i) == used.end()){
                v.push_back(nums[i]);
                used.insert(i);
                findPermutation(nums, v, used);
                v.pop_back();
                used.erase(i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        set<int> st;
        findPermutation(nums, {}, st);
        return ans;
    }
};
