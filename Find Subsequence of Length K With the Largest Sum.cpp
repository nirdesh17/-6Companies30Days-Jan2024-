class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }
        vector<pair<int,int>> v;
        for(int i=0;i<k;i++)
        {
            pair<int,int> a=pq.top();
            pq.pop();
            v.push_back({a.second,a.first});
        }
        vector<int> ans;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};