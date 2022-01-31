class Solution{
public:
    int height(int N){
        
        for(int i=1;i<=N;i++)
        {
            if(i*(i+1)<2*N) continue;
            else if(i*(i+1)==2*N) return i;
            else return i-1;
        }
        
        return -1;
    }
};
