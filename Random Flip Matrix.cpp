class Solution {
public:
    int row=0,col=0,mx=0;
    unordered_set<int> v;
    Solution(int m, int n) {
        mx=m*n;
        row=m;
        col=n;
    }
    
    vector<int> flip() {
        if(v.size()==mx) return {};
        int r=rand()%mx;
        while(v.count(r))
        {
            r=(++r)%mx;
        }
        v.insert(r);
        return {r/col,r%col};
    }
    
    void reset() {
        v={};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */