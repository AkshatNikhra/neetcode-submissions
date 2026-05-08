class Solution {
public:
    bool isValid(char c){
        if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
        return false;
    }
    string combine(string s){
        int n = s.length();
        string st = "";
        for(char c : s){
            if(isValid(c)) st += tolower(c);
        }
        return st;
    }
    bool isPalindrome(string s) {
        s = combine(s);
        int n = s.length();
        int i = 0, j = n - 1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
