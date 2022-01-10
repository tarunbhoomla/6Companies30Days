// Column name from a given column number 
// Medium Accuracy: 49.85% Submissions: 3375 Points: 4
// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
// Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc.
//  In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA” and so on.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string res="" ;
        while(n)
        {

            int  idx = n%26 ;
            char x ;
            if(idx==0)
             {
                 x = 'Z' ;
                 n-- ;
             }
             else
             {
                x = 'A'+idx-1 ;                 
             }

            res = x + res ;
            
            n = n/26 ;
            
        }
        
        return res ;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends