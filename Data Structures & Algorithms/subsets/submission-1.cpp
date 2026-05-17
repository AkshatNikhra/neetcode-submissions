class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        // int p = pwer(n);
        vector<vector<int>> ans;
        for(int b=0;b<(1<<n);b++){
            vector<int> v;
            for(int i=0;i<n;i++){
                if(b&(1<<i)) v.push_back(nums[i]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
