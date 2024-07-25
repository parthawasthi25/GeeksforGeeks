//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long gcd(long long A, long long B) {
    while (B != 0) {
        long long temp = B;
        B = A % B;
        A = temp;
    }
    return A;
}
    vector<long long> lcmAndGcd(long long A , long long B) {
        long long gcd_val = gcd(A, B);
        long long lcm = (A * B) / gcd_val;
        return {lcm, gcd_val};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends