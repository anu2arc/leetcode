#include <bits/stdc++.h>

using namespace std;

int main()
{
    return 0;
}

// this solution is of O(n^2) and can be improved further plus it uses extra space;

class Solution
{
public:
    static bool check(string s, int start, int end)
    {
        vector<bool> occ(256, false);
        for (int i = start; i <= end; i++)
        {
            if (occ[s[i]])
                return false;
            occ[s[i]] = true;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (check(s, i, j))
                    count = max(count, j - i + 1);
            }
        }
        return count;
    }
};

// this one use dp to reduce the time complexity of the previos approach by storing the last check value

class Solution
{
public:
    static bool check(string s, int start, int end, vector<vector<bool>> &dp)
    {
        if (start != end && !dp[start][end - 1])
            return dp[start][end] = false;
        for (int i = start; i < end; i++)
        {
            if (s[i] == s[end])
                return dp[start][end] = false;
        }
        return dp[start][end] = true;
    }
    int lengthOfLongestSubstring(string s)
    {
        int count = 0, n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (check(s, i, j, dp))
                    count = max(count, j - i + 1);
                else
                    break;
            }
        }
        return count;
    }
};

// this one is the best apporach for the following question it uses dp and solves the problem time complexity is O(n) ans
// extra space is used the is O(256) which is constant

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0, lv = 0;
        vector<int> dp(256, -1);
        for (int i = 0; i < s.size(); i++)
        {
            lv = max(lv, dp[s[i]] + 1);
            ans = max(ans, i - lv + 1);
            dp[s[i]] = i;
        }
        return ans;
    }
};