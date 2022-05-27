#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    return 0;
}



//Solution here


//Time complexity is:O(nlong)
//space Complexity is:O(1)
//can be reduced Further:yes

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m;
        for(int x:nums2)
        {
            nums1[i++]=x;
        }
        sort(nums1.begin(),nums1.end());
    }
};

//Time complexity is:O(N)
//space Complexity is:O(1)
//can be reduced Further: NO

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=m+n-1;
        m--;n--;
        while(m>=0 && n>=0)
        {
            if(nums1[m]>nums2[n])
                nums1[k--]=nums1[m--];
            else
                nums1[k--]=nums2[n--];
        }
        while(n>=0)
            nums1[k--]=nums2[n--];  
    }
};
