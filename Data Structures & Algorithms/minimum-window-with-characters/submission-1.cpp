class Solution {
public:
    bool isMatch(const vector<int>& vs, const vector<int>& vt){
        int n = vt.size();
        for(int i=0;i<n;i++){
            if(vs[i] < vt[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int sz = INT_MAX;
        int index = -1;

        int n = s.length();
        int m = t.length();

        if(m > n) return "";

        vector<int> vt(150), vs(150);
        for(char c:t) vt[c]++;

        int j = 0;
        for(int i=0;i<n;i++){
            vs[s[i]]++;
            while(j <= i && isMatch(vs, vt)){
                if(i - j + 1 < sz){
                    sz = i - j + 1;
                    index = j;
                }
                vs[s[j]]--;
                j++;
            }
        }


        if(index == -1) return "";
        
        return s.substr(index, sz);
    }
};
