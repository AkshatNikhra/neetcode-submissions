class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b)
        {
            int disA = a.first * a.first + a.second * a.second;
            int disB = b.first * b.first + b.second * b.second;
            return disA > disB;
        };
        vector<vector<int>> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        int n = points.size();
        for(int i=0;i<n;i++){
            pq.push({points[i][0], points[i][1]});
        }
        while(k--){
            // cout << pq.top().first << " " << pq.top().second << '\n';
            // pq.pop();
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return ans;

    }
};
