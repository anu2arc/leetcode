#include <bits/stdc++.h>

using namespace std;

int main()
{
    return 0;
}

// solution here

// optimised solution

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int k, n = nums.size();
        for (k = n - 2; k >= 0; k--)
        {
            if (nums[k] < nums[k + 1])
                break;
        }
        if (k < 0)
            sort(nums.begin(), nums.end());
        else
        {
            int i = n - 1;
            for (; i >= 0; i--)
            {
                if (nums[i] > nums[k])
                    break;
            }
            swap(nums[i], nums[k]);
            cout << i << k;
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};

// worse solution here this solution is not correct;
class Solution
{
public:
    void solve(vector<vector<int>> &per, vector<int> &nums, int start)
    {
        if (start == nums.size())
        {
            per.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[i], nums[start]);
            solve(per, nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
    bool check(vector<int> a, vector<int> b)
    {
        cout << a.size();
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                return false;
        return true;
    }
    void nextPermutation(vector<int> &nums)
    {
        vector<vector<int>> per;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        solve(per, temp, 0);
        for (int i = 0; i < per.size(); i++)
        {
            for (int j = 0; j < per[i].size(); j++)
                cout << per[i][j];
            cout << ends;
            vector<int> temp;
            bool x = next_permutation(per[i].begin(), per[i].end());
            for (int j = 0; j < per[i].size(); j++)
                cout << temp[j];
            cout << endl;
        }
        int i = 0;
        for (; i < per.size(); i++)
        {
            if (check(per[i], nums))
                break;
        }
        cout << i;
        if (i < per.size() - 1)
            nums = per[i + 1];
        nums = per[0];
    }
};