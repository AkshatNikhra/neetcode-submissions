class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int x:nums) st.insert(x);
        int ans = 0;
        for(int x:nums){
            if(st.find(x - 1) == st.end()){
                int len = 1;
                while(st.find(x+len) != st.end()) {
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
