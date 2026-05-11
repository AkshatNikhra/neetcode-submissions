class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> st;
        vector<int> ans(n, 0);
        for(int i=0;i<n;i++){
            if(st.empty() || st.top().first >= temperatures[i]){
                st.push({temperatures[i], i});
            }else{
                while(!st.empty() && st.top().first < temperatures[i]){
                    pair<int,int> p = st.top();
                    st.pop();
                    ans[p.second] = i - p.second;
                }
                st.push({temperatures[i], i});
            }
        }
        return ans;
    }
};
