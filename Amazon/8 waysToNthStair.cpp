// Count ways to N'th Stair(Order does not matter) 
// Medium Accuracy: 51.45% Submissions: 26443 Points: 4
// There are N stairs, and a person standing at the bottom wants to reach the top.
//  The person can climb either 1 stair or 2 stairs at a time.
//   Count the number of ways, the person can reach the top (order does not matter).

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
        long long dp[m+1] ;
        dp[0]=1 ;
        dp[1] = 1 ;
        for(int i=2 ; i<=m ; i++)
        {
            dp[i] = 1 + dp[i-2] ;
        }
        
        return dp[m] ;
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends