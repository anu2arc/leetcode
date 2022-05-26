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