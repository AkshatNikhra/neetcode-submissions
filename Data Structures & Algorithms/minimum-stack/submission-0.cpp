class MinStack {
public:
    vector<pair<int,int>> v; // first is element and second is minimum 
    MinStack() {
        v.clear();
    }
    
    void push(int val) {
        if(v.empty()) v.push_back({val, val});
        else {
            pair<int,int> topp = v.back();
            int mi = min(val, topp.second);
            v.push_back({val, mi});
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};
