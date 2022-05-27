#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    return 0;
}

// Solution here

// Time complexity is:O(nlogn)
// space Complexity is:O(n)
// can be reduced Further: NO

class Solution
{
public:
    static bool comp(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }
    bool isoverlapping(vector<int> a, vector<int> b)
    {
        return a[0] <= b[0] && a[1] >= b[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), comp);
        ans.push_back(intervals[0]);
        int count = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (isoverlapping(ans[count], intervals[i]))
            {
                ans[count][1] = max(ans[count][1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
                count++;
            }
        }
        return ans;
    }
};