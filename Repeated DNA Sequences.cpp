class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        int i=0,j=9;
        while(i + 10 <= s.length())
        {
            string a=s.substr(i,10);
            mp[a]++;
            i++;
        }
        vector<string> ans;
        if(!mp.empty())
        {
            for(auto j:mp)
            {
                if(j.second>1)
                {
                    ans.push_back(j.first);
                }
            }
        }
        
        return ans;
    }
};