class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int start = 0, end = n - 1;
        int ans = -1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] >= nums[0] && nums[mid] >= nums[n - 1]){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return nums[(ans + 1)%n];
    }
};
