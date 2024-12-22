//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        // If the array size is 1, no jumps are needed.
        if (n <= 1) return 0;

        // If the first element is 0, we cannot move forward.
        if (arr[0] == 0) return -1;

        // Initialize variables:
        int maxReach = arr[0]; // The farthest point that can be reached.
        int steps = arr[0];    // Steps remaining in the current jump.
        int jumps = 1;         // Number of jumps taken so far.

        // Traverse the array:
        for (int i = 1; i < n; i++) {
            // Check if we have reached the end of the array.
            if (i == n - 1) return jumps;

            // Update maxReach.
            maxReach = max(maxReach, i + arr[i]);

            // Use a step to move to the next index.
            steps--;

            // If no steps are left:
            if (steps == 0) {
                jumps++; // Increment the jump count.

                // Check if the current index is beyond maxReach.
                if (i >= maxReach) return -1;

                // Reinitialize steps for the next jump.
                steps = maxReach - i;
            }
        }

        return -1; // If we cannot reach the end.
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends