#include <bits/stdc++.h>

using namespace std;

int main()
{
    return 0;
}

// solution here
// brute force solution time complection O(n^3)

class Solution
{
public:
    bool check(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (check(s, i, j) && j - i + 1 > ans.size())
                {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};

// dp solution time complexity is around O(N*N) plus extra space O(N*N)

class Solution
{
public:
    bool check(string &s, int i, int j, vector<vector<bool>> &dp)
    {
        if (i != j && !dp[i + 1][j - 1])
            return dp[i][j] = false;
        return dp[i][j] = s[i] == s[j];
    }
    string longestPalindrome(string s)
    {
        int n = s.size(), start = 0, maxlength = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                maxlength = 2;
                start = i;
            }
        }
        for (int k = 3; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = i + k - 1;
                if (dp[i + 1][j - 1] && s[i] == s[j])
                {
                    dp[i][j] = true;

                    if (k > maxlength)
                    {
                        start = i;
                        maxlength = k;
                    }
                }
            }
        }
        return s.substr(start, maxlength);
    }
};

// leetcode expand around centre solution time complextity is O(n^2) and no extra space

class Solution
{
public:
    static int expand(string s, int i, int j)
    {
        while (i >= 0 && j < s.size() && s[i] == s[j])
        {
            i--;
            j++;
        }
        return j - i - 1;
    }
    string longestPalindrome(string s)
    {
        if (s.size() < 1)
            return "";
        int start = 0, end = 0, len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start + 1)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

// Manacher's Algorithm time complexity O(N) no extra space

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string w = "@#";
        for (int i = 0; i < s.size(); i++)
        {
            w = w + s[i] + '#';
        }
        w += '$';
        int arr[w.size()];
        memset(arr, 0, sizeof(arr));
        int c = 0, r = 0;
        for (int i = 1; i < w.size() - 1; i++)
        {
            int mir = 2 * c - i;
            if (i < r)
            {
                arr[i] = min(r - i, arr[mir]);
            }
            while (w[i + (1 + arr[i])] == w[i - (1 + arr[i])])
            {
                arr[i]++;
            }
            if (i + arr[i] > r)
            {
                c = i;
                r = i + arr[i];
            }
        }
        int maxindex = 0;
        for (int i = 1; i < w.size(); i++)
        {
            if (arr[i] > arr[maxindex])
                maxindex = i;
        }
        cout << arr[maxindex];
        return s.substr((maxindex - 1 - arr[maxindex]) / 2, arr[maxindex]);
    }
};