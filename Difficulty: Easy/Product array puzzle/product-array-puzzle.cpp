//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n = nums.size();
        vector<long long int> result(n, 1);
        long long int prefixProduct = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = prefixProduct;
            prefixProduct *= nums[i];
        }
        long long int suffixProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }
        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends