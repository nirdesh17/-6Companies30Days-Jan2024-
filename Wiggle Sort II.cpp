class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> ans(nums);
        sort(ans.begin(),ans.end());
        for(int i=nums.size()-1,j=0,k=i/2+1;i>=0;i--)
        {
            nums[i]=ans[i&1?k++:j++];
        }
    }
};