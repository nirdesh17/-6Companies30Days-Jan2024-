class Solution {
public:

    int solve(string s)
    {
        int a=stoi(s);
        int b=a%100;
        a=a/100;
        a=a*60;
        return a+b;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& a) {
        int n=a.size();
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            int b=solve(a[i][1]);
            mp[a[i][0]].push_back(b);
        }

        vector<string> ans;
        for(auto e:mp)
        {
            sort(e.second.begin(),e.second.end());
            for(int i=0;i<e.second.size();i++)
            {
                int cnt=1;
                for(int j=i+1;j<e.second.size();j++)
                {
                    if(e.second[j]-e.second[i]<60)
                    {
                        cnt++;
                    }
                    else
                        break;
                }
                if(cnt>=3)
                {
                    ans.push_back(e.first);
                    break;
                }
            }
        }
        return ans;
    }
};