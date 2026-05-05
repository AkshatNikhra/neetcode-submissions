class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) != mp.end()){
                return {mp[nums[i]], i};
            }
            mp[target - nums[i]] = i;
        }
        return {};
    }
};
