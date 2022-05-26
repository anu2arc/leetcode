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
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        for (int i = 0; i < n; i++)
        {
            curr.push_back(1);
            ans.push_back(curr);
            for (int j = 1; j < curr.size() - 1; j++)
            {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};