//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
class Solution {
public:
    static bool comparator(Job a, Job b) {
        return a.profit > b.profit;
    }
    
    int find(int parent[], int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }
    
    void unionSet(int parent[], int u, int v) {
        parent[v] = u;
    }

    vector<int> JobScheduling(Job arr[], int n) {
        // Sort jobs by decreasing order of profit
        sort(arr, arr + n, comparator);
        
        // Find the maximum deadline
        int maxDeadline = -1;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        // Create a parent array to represent the disjoint sets
        int parent[maxDeadline + 1];
        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }

        int countJobs = 0, jobProfit = 0;
        for (int i = 0; i < n; i++) {
            int availableSlot = find(parent, arr[i].dead);
            if (availableSlot > 0) {
                unionSet(parent, find(parent, availableSlot - 1), availableSlot);
                countJobs++;
                jobProfit += arr[i].profit;
            }
        }

        return {countJobs, jobProfit};
    }
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends