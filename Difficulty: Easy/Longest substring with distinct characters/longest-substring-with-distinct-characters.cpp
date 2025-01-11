//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        if (n == 0) return 0;
        unordered_map<char, int> lastOccurrence;
        int maxLength = 0;
        int start = 0; 

        for (int end = 0; end < n; ++end) {
            char currentChar = s[end];
            if (lastOccurrence.find(currentChar) != lastOccurrence.end() && lastOccurrence[currentChar] >= start) {
                start = lastOccurrence[currentChar] + 1; 
            }
            lastOccurrence[currentChar] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends