class Solution {
public:
    void solve(int i,vector<string>& ans,string out,string d,string mp[])
    {
        if(i>=d.length())
        {
            ans.push_back(out);
            return;
        }

        int n=d[i]-'0';
        string s=mp[n];
        for(int j=0;j<s.size();j++)
        {
            out.push_back(s[j]);
            solve(i+1,ans,out,d,mp);
            out.pop_back();
        }
    }
    vector<string> letterCombinations(string d) {
        vector<string> ans;
        string out;
        if(d.length()==0)
            return ans;
        
        string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,ans,out,d,mp);
        return ans;
    }
};