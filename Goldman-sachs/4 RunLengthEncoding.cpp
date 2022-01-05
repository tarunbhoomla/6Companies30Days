// Run Length Encoding 
// Easy Accuracy: 33.12% Submissions: 32858 Points: 2
// Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
// eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
   int n = src.length() ;
   char curr ;
   string res="";
   curr=src[0];
   int count=1 ;
   for(int i=0 ; i<n ;i++)
    {
        while(i<n-1 && curr == src[i+1] )
         {
            count++ ;
            i++ ;
         }
        res +=curr ;
        res += to_string(count) ;
        curr = src[i+1];
        count=1 ;

    }
  return res ;
} 
