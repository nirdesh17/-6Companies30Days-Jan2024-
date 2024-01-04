class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;
        for(int i=0;i<nums.size();i++)
        {
            vector<int> a;
            int cnt=0;
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j]%p==0)
                {
                    cnt++;
                }
                a.push_back(nums[j]);
                if(cnt>k)
                    break;
                
                s.insert(a);
            }
        }
        return s.size();
    }
};