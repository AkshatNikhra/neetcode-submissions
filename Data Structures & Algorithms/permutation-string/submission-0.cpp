class Solution {
public:
    bool matching(const vector<int>& f, const vector<int>& k){
        for(int i=0;i<26;i++){
            if(f[i] != k[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n > m) false;
        vector<int> v(26), mat(26);
        for(char c:s1) mat[c - 'a']++;

        for(int i=0;i<n;i++){
            v[s2[i] - 'a']++;
        }
        if(matching(v, mat)) return true;
        int j = 0;
        for(int i=n;i<m;i++){
            v[s2[j] - 'a']--;
            v[s2[i] - 'a']++;
            j++;
            if(matching(v, mat)) return true;
        }
        return false;
    }
};
