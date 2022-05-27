#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    return 0;
}

//Solution here


//Time complexity is:O(nlogn)
//space Complexity is:O(1)
//can be reduced Further: YEs

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                return nums[i];
        }
        return -1;
    }
};


//Time complexity is:O(n)
//space Complexity is:O(n)
//can be reduced Further: Yes

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (auto &num : nums) {
            if (seen.count(num))
                return num;
            seen.insert(num);
        }
        return -1;
    }
};

//Time complexity is:O(n)
//space Complexity is:O(1)
//can be reduced Further:Yes can be done withought modifying the array
// modification made in array

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int x:nums)
        {
            if(nums[abs(x)]<0)
                return abs(x);
            nums[abs(x)]*=-1;
        }
        return -1;
    }
};


//Time complexity is:O(N)
//space Complexity is:O(N)
//can be reduced Further: Yes reducing space complexity 


class Solution {
public:
    int store(vector<int>& nums, int cur) {
        if (cur == nums[cur])
            return cur;
        int nxt = nums[cur];
        nums[cur] = cur;
        return store(nums, nxt);
    }
    
    int findDuplicate(vector<int>& nums) {
        return store(nums, 0);
    }
};


//Time complexity is:O(N)
//space Complexity is:O(1)
//can be reduced Further: BEST SOLUTION YOU CAN POSSIBLY HAVE

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while (nums[0] != nums[nums[0]])
            swap(nums[0], nums[nums[0]]);
        return nums[0];
    }
};