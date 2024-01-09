class Solution {
public:
    bool solve(vector<int>& nums, int s, int e) 
    {
        int prev = 0;

        for (int k=0;k<nums.size();++k) 
        {
            if (k>=s && k<=e) 
            {
                continue;
            }

            if (nums[k]<=prev) 
            {
                return false;
            }

            prev=nums[k];
        }
        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) 
    {
        int res=0;
        int n=nums.size();

        for (int s=0;s<n;++s) 
        {
            for (int e=s;e<n;++e) 
            {
                if (solve(nums,s,e)) 
                {
                    res++;
                }
            }
        }

        return res;
    }

};