#include <bits/stdc++.h>

using namespace std;

int main()
{
    return 0;
}

// solution here





//optimised solution

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k,n=nums.size();
        for(k=n-2;k>=0;k--)
        {
            if(nums[k]<nums[k+1])
                break;
        }
        if(k<0)
            sort(nums.begin(),nums.end());
        else
        {
            int i=n-1;
            for(;i>=0;i--)
            {
                if(nums[i]>nums[k])
                    break;
            }
            swap(nums[i],nums[k]);
            cout<<i<<k;
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};