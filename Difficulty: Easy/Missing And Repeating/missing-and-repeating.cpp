//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int repeating = -1, missing = -1;

        // Step 1: Mark visited elements by making them negative
        for (int i = 0; i < n; i++) {
            int index = abs(arr[i]) - 1; // Get the index corresponding to the value

            if (arr[index] < 0) {
                repeating = abs(arr[i]); // If already negative, this is the repeating number
            } else {
                arr[index] = -arr[index]; // Mark as visited
            }
        }

        // Step 2: Find the missing number
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                missing = i + 1; // Index + 1 gives the missing number
                break;
            }
        }

        return {repeating, missing};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends