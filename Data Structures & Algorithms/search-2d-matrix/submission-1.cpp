class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col = -1;
        int startc = 0, endc = n - 1;
        while(startc <= endc){
            int mid = (startc + endc) / 2;
            if(target >= matrix[mid][0] && target <= matrix[mid][m-1]){
                cout << "A" << '\n';
                col = mid;
                break;
            }else if(target < matrix[mid][0]){
                cout << "B" << '\n';
                endc = mid - 1;
            }else{
                cout << "C" << '\n';
                startc = mid + 1;
            }
        }
        cout << col << '\n';
        if(col == -1) return false;

        startc = 0;
        endc = m - 1;
        while(startc <= endc){
            int mid = (startc + endc) / 2;
            if(target == matrix[col][mid]) return true;
            else if(target < matrix[col][mid]) endc = mid - 1;
            else startc = mid + 1;
        }
        return false;
    }
};
