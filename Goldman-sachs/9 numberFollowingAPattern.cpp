// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S)
    {
        stack<int> s ;
        string ans = "" ;
        int n = 1 ;
        for(int i=0 ; i< S.size() ;i++)
         {
             char a = S[i] ;
             if(a=='D')
               s.push(n++) ;
             else
             {
                 s.push(n++) ;
                 while(!s.empty())
                 {
                     char a1 = '0'+s.top() ;
                     ans += a1 ;
                     s.pop() ;
                 }
             }
         }
         s.push(n++) ;
         while(!s.empty())
         {
             char a1 = '0'+s.top() ;
             ans += a1 ;
             s.pop() ;
         }
        return ans ;
    }
    
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends