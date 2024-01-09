class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dT) {
        vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
        for(auto it:edges)
        {
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                        continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        int cntCity=n;
        int noCity=-1;
        for(int c=0;c<n;c++)
        {
            int cnt=0;
            for(int c1=0;c1<n;c1++)
            {
                if(dist[c][c1]<=dT)
                {
                    cnt++;
                }
            }
            if(cnt<=cntCity)
            {
                cntCity=cnt;
                noCity=c;
            }
        }
        return noCity;
    }
};