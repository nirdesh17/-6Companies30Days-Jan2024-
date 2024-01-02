class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& comb, int k, int n, int i)
    {
        if(k==0 && n==0)
        {
            ans.push_back(comb);
            return;
        }

        if(k==0 || n==0 || i>9)
            return;

        for(int num=i;num<=9;num++)
        {
            comb.push_back(num);
            solve(ans,comb,k-1,n-num,num+1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(ans,comb,k,n,1);
        return ans;
    }
};