// Find Missing And Repeating 
// Medium Accuracy: 37.77% Submissions: 82129 Points: 4
// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    pair<int,int> helper(int *arr , int n)
     {
         int miss = 0 ;
         int rep = 0 ;
         
         for(int i=0 ; i< n ;i++)
          {
              int idx = abs(arr[i]) - 1 ;
              if(arr[idx] > 0 )
                arr[idx] = (-1)*(arr[idx]) ;
              else
                rep = abs(arr[i]) ;
          }
         for(int i=0 ; i<n ;i++)
          {
              if(arr[i] > 0)
                miss = i+1 ;
          }
        
        return {rep,miss} ;
     }
    int *findTwoElement(int *arr, int n) 
    {
        int *res = new int[2]; 
        pair<int,int> ans = helper(arr , n) ;
        res[0] = ans.first ;
        res[1] = ans.second ;
        
        return res ;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends