class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        if(k > n) return {};
        int ma = INT_MIN;
        for(int i=0;i<k;i++) {
            mp[nums[i]]++;
            ma = max(ma, nums[i]);
        }
        vector<int> ans;
        ans.push_back(ma);
        int j = 0;
        for(int i=k;i<n;i++){
            mp[nums[j]]--;
            if(mp[nums[j]] == 0) mp.erase(nums[j]);
            mp[nums[i]]++;
            auto it = mp.rbegin();
            ans.push_back(it->first);
            j++;
        }
        return ans;
    }
};
