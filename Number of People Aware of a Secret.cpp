const int mod = 1e9+7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(2005,0);

        dp[1]=1;
        for(int j=1;j<=n;j++)
        {
            for(int i=j+delay;i<j+forget;i++)
            {
                dp[i]=(dp[i]+dp[j])%mod;
            }
        }

        int ans=0;
        for(int j=max(n-forget+1,1);j<=n;j++)
        {
            ans=(ans+dp[j])%mod;
        }
        return ans;
    }
};