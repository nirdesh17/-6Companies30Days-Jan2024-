class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        int n=w.size();
        int m=w[0].size();
        vector<vector<int>> res(n,vector<int> (m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(w[i][j]==1)
                    res[i][j]=0;
                if(res[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        vector<int> dir={0,1,0,-1,0};
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int a=p.first+dir[i];
                int b=p.second+dir[i+1];
                if(a>=0 && a<n && b>=0 && b<m && res[a][b]==-1)
                {
                    res[a][b]=res[p.first][p.second]+1;
                    q.push({a,b});
                }
            }
        }

        return res;
    }
};