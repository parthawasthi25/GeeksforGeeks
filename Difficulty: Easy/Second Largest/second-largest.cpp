//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int largest = -1, secondLargest = -1;

        // Iterate through the array
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > largest) {
                // Update secondLargest before updating largest
                secondLargest = largest;
                largest = arr[i];
            } else if (arr[i] > secondLargest && arr[i] < largest) {
                // Update secondLargest if arr[i] is between largest and secondLargest
                secondLargest = arr[i];
            }
        }

        return secondLargest;
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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends