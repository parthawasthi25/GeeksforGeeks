//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    stack<int> s;
    stack<int> minStack; // Auxiliary stack to keep track of minimum values
  
  public:
    Solution() {
        while (!s.empty()) s.pop();
        while (!minStack.empty()) minStack.pop();
    }

    // Add an element to the top of Stack
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (!s.empty()) {
            if (s.top() == minStack.top()) {
                minStack.pop();
            }
            s.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        return s.empty() ? -1 : s.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends