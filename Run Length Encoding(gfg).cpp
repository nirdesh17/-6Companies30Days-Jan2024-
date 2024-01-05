//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
    int cnt=0;
    char a=src[0];
    string ans="";
    for(int i=0;i<src.length();i++)
    {
        if(src[i]==a)
        {
            cnt++;
        }
        else
        {
            ans.push_back(a);
            ans+=to_string(cnt);
            cnt=1;a=src[i];
        }
    }
    ans.push_back(a);
    ans+=to_string(cnt);
    return ans;
}     
 