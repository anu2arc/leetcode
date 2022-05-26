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
    string prefix(string &a, string &b)
    {
        string ans = "";
        for (int i = 0; i < min(a.size(), b.size()); i++)
        {
            if (a[i] == b[i])
                ans += a[i];
            else
                break;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        return prefix(strs[0], strs[strs.size() - 1]);
    }
};