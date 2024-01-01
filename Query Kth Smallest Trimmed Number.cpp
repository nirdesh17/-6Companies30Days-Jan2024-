
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n=nums.size();
        for(auto q:queries)
        {
            vector<pair<string,int>> pq;
            for(int i=0;i<n;i++)
            {
                pq.push_back({nums[i].substr(nums[i].size()-q[1]),i});
            }
            sort(pq.begin(),pq.end());
            ans.push_back(pq[q[0]-1].second);
        }
        return ans;
    }
};