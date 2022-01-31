class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        int  prv = arr[0];
        vector<int> v;
        int mx = -1;
        for(int i=N-1;i>=0;i--)
        {
            mx = max(mx,  arr[i]);
             v.push_back(mx);
            
        }
        
        reverse(v.begin(), v.end());
        for(int i=1;i<N-1;i++)
        {
            if(arr[i]>prv && arr[i]<v[i+1]) return {prv, arr[i], v[i+1]};
            prv = min(prv, arr[i]);
        }
        
        return {};
    }
};
