// Array Pair Sum Divisibility Problem 
// Easy Accuracy: 45.91% Submissions: 12881 Points: 2
// Given an array of integers and a number k, write a function that returns true if given array can be 
// divided into pairs such that sum of every pair is divisible by k.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
bool canPair(vector<int> a, int k) {
       map<int,int>m;
       int n=a.size();
       for(int i=0;i<n;i++){
           m[a[i]%k]++;
       }
       for(int i=0;i<n;i++){
           int r=a[i]%k;
           if(r==0){
               if(m[0]%2 != 0 )return 0;
           }
           else if(m[r]!=m[k-r])return 0;
       }
       return 1;
       
   }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends