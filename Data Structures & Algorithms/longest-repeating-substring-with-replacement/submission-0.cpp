class Solution {
public:
    int maxOpNeeded(const map<char,int>& mp, int tot){
        int ma = 0;
        for(auto x:mp){
            ma = max(ma, x.second);
        }
        return tot - ma;
    }
    int characterReplacement(string s, int k) {
        int n = s.length();
        map<char, int> mp;
        int len = 0;
        int j = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(maxOpNeeded(mp, i - j + 1) > k){
                mp[s[j]]--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
