//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> prefixSumIndex; // To store first occurrence of prefix sums
        int maxLength = 0; // Length of the longest subarray
        int prefixSum = 0; // Cumulative sum of elements (0s as -1)

        for (int i = 0; i < arr.size(); i++) {
            // Replace 0 with -1
            prefixSum += (arr[i] == 0) ? -1 : 1;

            // Check if the prefix sum is 0
            if (prefixSum == 0) {
                maxLength = i + 1; // Full array from 0 to i has equal 0s and 1s
            }

            // Check if this prefix sum has been seen before
            if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end()) {
                // Calculate the length of the subarray
                maxLength = max(maxLength, i - prefixSumIndex[prefixSum]);
            } else {
                // Store the first occurrence of this prefix sum
                prefixSumIndex[prefixSum] = i;
            }
        }

        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends