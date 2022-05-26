#include <bits/stdc++.h>

using namespace std;

int main()
{
    return 0;
}

// solution here

// this is a O(nlogn) solution with extra memory of O(n);

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int l = nums1.size();
        if (l & 1)
        {
            return (double)nums1[l / 2];
        }
        else
        {
            return (double)(nums1[(l - 1) / 2] + nums1[l / 2]) / 2;
        }
    }
};

// This solution takes O(n+m) time and O(n+m) extra space

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        while (i < n1 && j < n2)
        {
            if (nums1[i] < nums2[j])
                ans.push_back(nums1[i++]);
            else
                ans.push_back(nums2[j++]);
        }
        while (i < n1)
        {
            ans.push_back(nums1[i++]);
        }
        while (j < n2)
        {
            ans.push_back(nums2[j++]);
        }
        int l = ans.size();
        if (l & 1)
        {
            return (double)ans[l / 2];
        }
        else
        {
            return (double)(ans[(l - 1) / 2] + ans[l / 2]) / 2;
        }
    }
};


// this is O(logn) solution 
// https://www.youtube.com/watch?v=NTop3VTjmxk refer this video for explanation 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);
        int n1=nums1.size();
        int n2=nums2.size();
        int low=0,high=n1;
        
        while(low<=high)
        {
            int cut1=(low+high)>>1;
            int cut2=(n1+n2+1)/2-cut1;
            
            int left1=cut1==0?INT_MIN:nums1[cut1-1];
            int left2=cut2==0?INT_MIN:nums2[cut2-1];

            int right1=cut1==n1?INT_MAX:nums1[cut1];
            int right2=cut2==n2?INT_MAX:nums2[cut2];
            
            if(left1<=right2 && left2<=right1)
            {
                if((n1+n2)%2==0) 
                    return (max(left1,left2)+min(right1,right2))/2.0;
                else
                    return max(left1,left2);
            }
            else if(left1>right2)
            {
                high=cut1-1;
            }
            else
            {
                low=cut1+1;
            }
        }
        return 0.0;
    }
};