class TimeMap {
public:

    map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        vector<pair<int,string>> v = mp[key];
        int n = v.size();
        int start = 0, end = n - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(v[mid].first <= timestamp){
                ans = v[mid].second;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return ans;
    }
};
