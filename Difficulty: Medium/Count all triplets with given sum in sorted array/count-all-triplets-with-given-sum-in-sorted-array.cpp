//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size();
        int count = 0;

        // Iterate through the array
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;  // The second pointer
            int right = n - 1;  // The third pointer

            // Use two-pointer technique to find pairs that add up with arr[i]
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == target) {
                    if (arr[left] == arr[right]) {
                        // If all elements are the same, count all combinations
                        int countPairs = right - left + 1;
                        count += (countPairs * (countPairs - 1)) / 2; // nC2
                        break;  // All combinations for this i are done
                    } else {
                        // Count duplicates for the left and right pointers
                        int leftCount = 1, rightCount = 1;

                        while (left + 1 < right && arr[left] == arr[left + 1]) {
                            left++;
                            leftCount++;
                        }
                        while (right - 1 > left && arr[right] == arr[right - 1]) {
                            right--;
                            rightCount++;
                        }

                        // Multiply counts and add to total
                        count += leftCount * rightCount;
                        left++;
                        right--;
                    }
                } else if (sum < target) {
                    left++;  // Increase sum by moving left pointer forward
                } else {
                    right--;  // Decrease sum by moving right pointer backward
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends