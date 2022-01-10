// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) 
	{
	   vector<char> order {'!','#','$','%','&','*','@','^','~'} ;
       
       unordered_map<char,int> m ;

       for(int i=0 ;i<n ;i++)
       {
           m[nuts[i]]++ ;
       }
       
       int j=0 ;
       for(int i=0 ;i<9 ;i++)
       {
          if(m[order[i]]>0)
          {
              nuts[j++] = order[i] ;
          }
            
       }
      int k=0;
       for(int i=0 ;i<9 ;i++)
       {
          if(m[order[i]]>0)
          {
              bolts[k++] = order[i] ;
          }
            
       }
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends