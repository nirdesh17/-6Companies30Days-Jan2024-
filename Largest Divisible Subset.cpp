class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> prev(n,-1);

        sort(nums.begin(),nums.end());

        int mxS=1;
        int mxI=0;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>mxS)
            {
                mxS=dp[i];
                mxI=i;
            }
        }
        vector<int> res;
        while(mxI!=-1)
        {
            res.push_back(nums[mxI]);
            mxI=prev[mxI];
        }
        return res;
    }
};