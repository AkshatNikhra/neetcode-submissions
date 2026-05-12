class Solution {
public:
    bool isPossible(const vector<int>& piles, long long h, long long mid){
        if (mid == 0) return false;
        long long ans = 0;
        for(long long int x:piles){
            ans += ((x + mid - 1LL) / mid);
        }
        return (ans<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long start = 1, end = 1e9 + 7;
        long long ans = -1;
        while(start <= end){
            long long mid = (start + end) / 2;
            if(isPossible(piles, h, mid)){
                ans = mid;
                end = mid - 1LL;
            }
else{
                start = mid + 1LL;
            }
        }
        return ans;
    }
};
