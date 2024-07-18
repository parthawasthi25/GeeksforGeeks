//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
   int evenlyDivides(int N){
        int count = 0;
        string s = to_string(N);
        int a = s.length();
        
        for(int i = 0; i < a; i++){
            if(s[i] == '0')
                continue;
            
            int digit = s[i] - '0'; 
            if (N % digit == 0) 
                count++;
        }
        
        return count; 
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends