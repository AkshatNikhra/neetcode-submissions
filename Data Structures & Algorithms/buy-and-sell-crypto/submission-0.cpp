class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = INT_MAX;
        int ans = 0;
        for(int x:prices){
            if(mi > x){
                mi = x;
            }else{
                ans = max(ans, x - mi);
            }
        }
        return ans;
    }
};
