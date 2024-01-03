//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int n=S.length();
        stack<int> st;
        string ans;
        int num=1;
        for(int i=0;i<n;i++)
        {
            if(S[i]=='D')
            {
                st.push(num++);
            }
            else
            {
                st.push(num++);
                while(!st.empty())
                {
                    ans+=(st.top()+'0');
                    st.pop();
                }
            }
        }
        st.push(num);
        while(!st.empty())
        {
            ans+=(st.top()+'0');
                st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 