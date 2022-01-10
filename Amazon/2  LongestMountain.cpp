// 845. Longest Mountain in Array
// Medium

// 1618

// 52

// Add to List

// Share
// You may recall that an array arr is a mountain array if and only if:

// arr.length >= 3
// There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given an integer array arr, return the length of the longest subarray, which is a mountain. 
// Return 0 if there is no mountain subarray.


class Solution {
public:
int longestMountain(vector<int>& a) 
{
        int i,ans=0,curr=0,n=a.size();
        for(i=1;i<n;i++)
        {
            if(a[i]==a[i-1]) 
                curr=0;            
            else if(a[i]>a[i-1]) 
                curr++;

            else if(curr>0)           
            {
                    while(i<n and a[i]<a[i-1])
                    {
                        curr++;
                        i++;
                    }
                    ans = max(ans,curr+1);
                    curr=0 ;
                    i--;
            }
        }
        return ans;
    }
};