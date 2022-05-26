#include <bits/stdc++.h>

using namespace std;

int main()
{
    return 0;
}

// solution here

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int msum = INT_MIN, curr = 0;
        for (auto x : nums)
        {
            curr += x;
            msum = max(msum, curr);
            curr = max(curr, 0);
        }
        return msum;
    }
};