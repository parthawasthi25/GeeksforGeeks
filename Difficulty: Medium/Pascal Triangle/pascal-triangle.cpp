//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        const int MOD = 1e9 + 7;
        vector<int> row;
        row.push_back(1); // First element is always 1

        for (int i = 1; i < n; ++i) {
            // Build row using previous values from right to left to avoid overwriting
            for (int j = i - 1; j >= 1; --j) {
                row[j] = (row[j] + row[j - 1]) % MOD;
            }
            row.push_back(1); // Last element is always 1
        }
        return row;
    }
};




//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends