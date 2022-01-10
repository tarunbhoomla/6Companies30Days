// Maximum of all subarrays of size k 
// Medium Accuracy: 44.42% Submissions: 55868 Points: 4
// Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans ;
        priority_queue<pair<int,int>> pq ;
        int i=0 , j=0 ;
        while(j<n)
        {
            if(j-i+1 < k)
            {
                pq.push({arr[j] , j }) ;
                j++ ;
            }
            else
            {
                pq.push({arr[j] , j}) ;
                int temp = pq.top().first ;
                ans.push_back(temp) ;
                while(!pq.empty())
                {
                    if(pq.top().second <=i)
                      pq.pop() ;
                    else
                      break ;
                }
               i++ ;
               j++ ;
            }
               
        }
        return ans ;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends