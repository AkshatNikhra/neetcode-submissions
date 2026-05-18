class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>> st;
        for(int b=0;b<(1<<n);b++){
            vector<int> v;
            for(int i=0;i<n;i++){
                if(b&(1<<i)) v.push_back(nums[i]);
            }
            sort(v.begin(), v.end());
            if(st.find(v) == st.end()) ans.push_back(v);

            st.insert(v);
        }
        return ans;
    }
};
