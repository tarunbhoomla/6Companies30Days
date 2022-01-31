class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        vector<int> v(b, 1);
        for(int i=1;i<a;i++)
        {
            vector<int> v2(b, 1);
            for(int j=1;j<b;j++)
            v2[j] = v2[j-1] + v[j];
            
            swap(v2, v);
        }
        
        return v[b-1];
    }
};
