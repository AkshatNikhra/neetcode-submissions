class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> v(300);
        int count = 0;
        int j = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            while(j <= i && v[s[i]] != 0){
                    v[s[j]]--;
                    j++;
                    count--;
            }
            v[s[i]]++;
            count++;

            ans = max(ans, count);

        }
        return ans;
    }
};
