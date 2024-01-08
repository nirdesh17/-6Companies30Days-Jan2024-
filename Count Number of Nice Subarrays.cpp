class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,odd=0,cnt=0,tot=0;
        for(int j=0;j<nums.size();j++)   
        {
            if(nums[j]&1)
            {
                odd++;
                if(odd>=k)
                {
                    cnt=1;
                    while(!(nums[i++]&1))
                        cnt++;
                    tot+=cnt;
                }
            }
            else if(odd>=k)
                tot+=cnt;
        }
        return tot;
    }
};