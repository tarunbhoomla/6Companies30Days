class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
       //Your code here
       int m =0;
       long long x = N, n = N;
       while(x)
       {
           m = m*10 + x%10;
           x/=10;
       }
       
      
       long long ans =power_(N, m);
   
        return ans;
    }

long long power_(int x, int y){
    long long temp; 
    if(y == 0) 
        return 1; 
    temp = power_(x, y / 2); 
    if (y % 2 == 0) 
        return (temp * temp)%mod; 
    else
    { 
        if(y > 0) 
            return (((x *temp)%mod) * temp)%mod; 
        else
            return ((temp * temp)%mod) / x; 
    }
}
}; 
