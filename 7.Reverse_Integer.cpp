#include <bits/stdc++.h>

using namespace std;

int main()
{
    return 0;
}

// solution here
// time complexity O(logn base 10)

class Solution
{
public:
    int reverse(int x)
    {
        long long n = 0;
        while (x)
        {
            n = n * 10 + x % 10;
            x /= 10;
        }
        return (n > INT_MAX || n < INT_MIN) ? 0 : (int)n;
    }
};