class Solution {
public:
    string getHint(string s, string g) {
        unordered_map<char,int> mp1,mp2;
        int bull=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==g[i])
                bull++;
            else
            {
                mp1[s[i]]++;
                mp2[g[i]]++;
            }
        }
        int cow=0;
        for(auto i:mp1)
        {
            char a=i.first;
            if(mp2.find(a)!=mp2.end())
            {
                cow+=min(mp1[a],mp2[a]);
            }
        }
        string ans=to_string(bull)+"A"+to_string(cow)+"B";
        return ans;
    }
};