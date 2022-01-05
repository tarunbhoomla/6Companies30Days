// 209. Minimum Size Subarray Sum
// Medium

// 5339

// 166

// Add to List

// Share
// Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous 
// subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no 
// such subarray, return 0 instead. 

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int i=0 , j=0 , sum = 0 ;
        int res = INT_MAX ;
        
        while(j<nums.size())
        {
            sum += nums[j] ;
            if(sum < target)
                 j++ ;
            else
            {
                while(sum >=target)
                {
                    res = min(res , j-i+1) ;
                    sum -= nums[i++] ;
                }
                j++ ;
            }
        }
       if(res == INT_MAX)
         return 0 ;
       
        return res ;
    }
};