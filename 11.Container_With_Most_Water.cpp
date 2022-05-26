#include <bits/stdc++.h>

using namespace std;

int main()
{
    return 0;
}

// solution here

// Brute force time complexitys is O(N^2);
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size(), ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans = max(ans, min(height[i], height[j]) * (j - i));
            }
        }
        return ans;
    }
};

// optimised time complexity O(N)

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size(), ans = INT_MIN;
        int i = 0, j = n - 1;
        while (i < j)
        {
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};