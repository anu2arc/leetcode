#include <bits/stdc++.h>

using namespace std;

int main()
{
    return 0;
}

// solution here

// time complexity is O(n) 
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        vector<string> ans(numRows);
        bool direction=false;
        int curr=0;
        for(char x:s)
        {
            ans[curr]+=x;
            if(curr==0 || curr==numRows-1) direction=!direction;
            curr+=(direction?1:-1);
        }
        string fa;
        for(string a:ans)
            fa+=a;
        return fa;
    }
};