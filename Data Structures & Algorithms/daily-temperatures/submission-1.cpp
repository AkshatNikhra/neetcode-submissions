class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for(int i=0;i<n;i++){
            if(st.empty() || temperatures[st.top()] >= temperatures[i]){
                st.push(i);
            }else{
                while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                    int p = st.top();
                    st.pop();
                    ans[p] = i - p;
                }
                st.push(i);
            }
        }
        return ans;
    }
};
