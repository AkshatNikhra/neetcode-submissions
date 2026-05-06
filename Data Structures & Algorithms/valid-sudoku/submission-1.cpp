class Solution {
public:
    bool isValidRow(const vector<vector<char>>& board){
        vector<int> v(10, 0);
        for(int i=0;i<9;i++){
            v.clear();
            v.resize(10, 0);
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                int value = board[i][j] - '0';
                cout << i << " " << j << " " << value << " " << v[value] << '\n'; 
                if(value < 1 && value > 9) return false;
                v[value]++;
                if(v[value] > 1) return false;
            }
        }
        return true;
    }

    bool isValidCol(const vector<vector<char>>& board){
        vector<int> v(10, 0);
        for(int i=0;i<9;i++){
            v.clear();
            v.resize(10, 0);
            for(int j=0;j<9;j++){
                if(board[j][i] == '.') continue;
                int value = board[j][i] - '0';
                cout << i << " " << j << " " << value << " " << v[value] << '\n'; 
                if(value < 1 && value > 9) return false;
                v[value]++;
                if(v[value] > 1) return false;
            }
        }
        return true;
    }

    bool isValidSubBox(const vector<vector<char>>& board){
        vector<int> v(10, 0);
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                v.clear();
                v.resize(10, 0);
                for(int k=i;k<i+3;k++){
                    for(int f=j;f<j+3;f++){
                        if(board[k][f] == '.') continue;
                        int value = board[k][f] - '0';
                        if(value > 9 && value < 1) return false;
                        v[value]++;
                        if(v[value] > 1) return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return isValidRow(board) && isValidCol(board) && isValidSubBox(board);
        
    }
};
