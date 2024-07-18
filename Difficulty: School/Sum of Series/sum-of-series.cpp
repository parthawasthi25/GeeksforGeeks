//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long seriesSum(long long n) {
        // code here
        long long sum;
        sum = (n*(n+1))/2;
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        long long res = obj.seriesSum(n);

        cout << res << endl;
    }
}

// } Driver Code Ends