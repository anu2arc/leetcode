
#include<bits/stdc++.h>

using namespace std;


// this is an order of O(n^2) solution and we will further improve it 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                    return {i,j};
            }
        }
        return {};
    }
};

// this solution is of O(n) and cannot be improved further with space complexity of O(n);

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        mp[nums[0]]=0;
        for(int i=1;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
                return {mp[target-nums[i]],i};
            mp[nums[i]]=i;
        }
        return {};
    }
};

int main()
{
    return 0;
}