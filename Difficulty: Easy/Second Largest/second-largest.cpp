//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        int n=arr.size();
        if(n<2){
            return -1;
        }
        sort(arr.begin(), arr.end());
        set<int>unique_elements(arr.begin(),arr.end());
        vector<int>uniqueelement(unique_elements.begin(), unique_elements.end());
        return uniqueelement[uniqueelement.size()-2];
        // Code Here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends