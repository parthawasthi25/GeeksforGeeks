//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int start = 0;
        int current_sum = 0;
        
        for(int end = 0; end < n; end++) {
            current_sum += arr[end];
            
            // Shrink the window as long as current_sum > target and start <= end
            while(current_sum > target && start < end){
                current_sum -= arr[start];
                start++;
            }
            
            // Check if current_sum equals target
            if(current_sum == target){
                // Return 1-based indices
                return {start + 1, end + 1};
            }
        }
        
        // If no subarray found, return -1
        return {-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends