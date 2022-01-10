// IPL 2021 - Match Day 2 
// Medium Accuracy: 65.11% Submissions: 5742 Points: 4
// Due to the rise of covid-19 cases in India, this year BCCI decided to organize knock-out
// matches in IPL rather than a league.

// Today is matchday 2 and it is between the most loved team Chennai Super Kings and the most underrated team - Punjab Kings.
//  Stephen Fleming, the head coach of CSK, analyzing the batting stats of Punjab. He has stats of runs scored by all
//  N players in the previous season and he wants to find the maximum score for each and every contiguous sub-list of 
//  size K to strategize for the game.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) 
    {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        int i=0,j=0;
        
        while(j < n){
            if(j-i+1 < k){
                pq.push({arr[j],j});
                j++;
            }else{
                pq.push({arr[j],j});
                int t = pq.top().first;
                ans.push_back(t);
                while(!pq.empty())
                {
                    if(pq.top().second <= i)
                    {
                        pq.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                i++,j++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends