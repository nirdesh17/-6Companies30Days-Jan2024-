//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int N) {
        // code here
        // solve using maths equation
        // x-missing, y-repeating
        long long n=N;
        long long sn = (n * (n + 1)) / 2;  // summation 1 to n
        long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;  // summation of sq of ele from 1 to n
        long long s = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            s += arr[i];  // summation of arr
            s2 += (long long)arr[i] * (long long)arr[i];  // summation of sq of ele from arr
        }

        long long v1 = s - sn;  // x-y
        long long v2 = s2 - s2n;

        v2 = v2 / v1;  // x+y
        long long x = (v1 + v2) / 2;
        long long y = x - v1;

        return {(int)x, (int)y};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}