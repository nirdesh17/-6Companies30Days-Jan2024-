class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int m=n/2;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=abs(nums[i]-nums[m]);
            cout<<cnt<<" ";
        }
        return cnt;
    }
};