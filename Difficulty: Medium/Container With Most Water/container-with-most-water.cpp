//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxWater(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        int max_area = 0;
        
        while (left < right) {
            int height = min(arr[left], arr[right]);
            int width = right - left;
            max_area = max(max_area, height * width);
            
            // Move the pointer pointing to the smaller height
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends