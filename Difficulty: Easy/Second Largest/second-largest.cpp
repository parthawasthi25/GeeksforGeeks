//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int largest = INT_MIN, second_largest = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {
            // Update the largest and second largest
            if (arr[i] > largest) {
                second_largest = largest;
                largest = arr[i];
            } 
            // Update second largest if arr[i] is distinct and greater than second largest
            else if (arr[i] > second_largest && arr[i] != largest) {
                second_largest = arr[i];
            }
        }

        // If second_largest is still INT_MIN, it means no second largest exists
        if (second_largest == INT_MIN) {
            return -1;
        }
        
        return second_largest;
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
    }
    return 0;
}

// } Driver Code Ends