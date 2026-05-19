class Solution {
public:
    vector<string> ans;
    bool isValid(string s){
        int count = 0;
        for(char c:s){
            if(c == '(') count++;
            else count--;
            if(count < 0) return  false;
        }
        return count == 0;
    }
    void generateAllParantheses(int index, int n, string s){
        if(index == n){
            if(isValid(s)) ans.push_back(s);
            return;
        }
        generateAllParantheses(index + 1, n, s + '(');
        generateAllParantheses(index + 1, n, s + ')');
    }
    vector<string> generateParenthesis(int n) {
        generateAllParantheses(0, 2 * n, "");
        return ans;
    }
};
