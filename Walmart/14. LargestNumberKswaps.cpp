class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       return find(0, k, str);
    }
    
    string find(int i, int k, string str)
    {
        if(i>=str.size()) return str;
        if(k==0) return str;
        string ans = str;
        for(int j=i+1;j<str.size();j++)
        {
            if(str[j]>str[i])
            {
                swap(str[i], str[j]);
                ans = max(ans, find(i+1, k-1, str));
                swap(str[i], str[j]);
            }
        }
        ans = max(ans, find(i+1, k, str));
        return  ans;
    }
};
