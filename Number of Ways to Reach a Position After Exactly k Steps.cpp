class Solution {
public:
    int m=1e9+7;
    int solve(int s,int e,int k,vector<vector<long long>>& dp)
    {
        if(k==0 && s==e)
            return 1;
        if(k==0)
            return 0;
        if(dp[s+1000][k]!=-1)
            return dp[s+1000][k];
        long long ans=solve(s+1,e,k-1,dp)+solve(s-1,e,k-1,dp);
        return dp[s+1000][k]=ans%m;
    }
    int numberOfWays(int s, int e, int k) {
        vector<vector<long long>> dp(4001,vector<long long> (1001,-1));
        long long ans=solve(s,e,k,dp);
        return ans%m;
    }
};