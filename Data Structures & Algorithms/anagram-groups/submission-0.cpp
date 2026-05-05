class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        map<string,vector<string>> mp;
        for(string s:strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
