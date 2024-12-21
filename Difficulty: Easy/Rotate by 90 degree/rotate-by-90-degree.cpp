//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        if(mat.size() == 0)
        return;
        
    int n;
    n = mat.size();
    
    for(int i=0; i<n/2; i++){
        for(int j=i; j<n-i-1; j++){
            int temp;
            temp = mat[i][j];
            mat[i][j] = mat[j][n-i-1];
            mat[j][n-i-1] = mat[n-i-1][n-j-1];
            mat[n-i-1][n-j-1] = mat[n-j-1][i];
            mat[n-j-1][i] = temp;
        }
    }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends