// First non-repeating character in a stream 
// Medium Accuracy: 51.34% Submissions: 33285 Points: 4
// Given an input stream of A of n characters consisting only of lower case alphabets. 
// The task is to find the first non repeating character, each time a character is inserted to the stream.
//  If there is no such character then append '#' to the answer.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A)
		{
    		int arr[26] ;
    		memset(arr,0,sizeof(arr)); 
		    queue<char> q ;


		    for(int i=0 ; i<A.size() ;i++)
		    {
                arr[A[i]-'a']++ ;
                if(arr[A[i]-'a']==1)
                  q.push(A[i]) ;
                
                while(!q.empty() && arr[q.front()-'a'] != 1)
                 q.pop() ;
                
                if(q.empty())
                  A[i] = '#' ;
                 
                 else
                   A[i] = q.front() ;
		        
		    }
		    
		    return A ;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends