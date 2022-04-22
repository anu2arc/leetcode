#include <bits/stdc++.h>

using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int m = 0;

        vector<int> visited(256, -1);
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            i = max(i, visited[s[j]] + 1);
            m = max(m, j - i + 1);
            visited[s[j]] = j;
        }
        return m;
    }
};