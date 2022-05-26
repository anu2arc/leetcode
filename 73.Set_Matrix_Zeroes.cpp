#include <bits/stdc++.h>

using namespace std;

int main()
{
    return 0;
}

// solution here
// this solutions space complexity can be reduced 
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<bool> row(matrix.size(), false);
        vector<bool> col(matrix[0].size(), false);
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
                if (!matrix[i][j])
                {
                    row[i] = true;
                    col[j] = true;
                }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            if (row[i])
            {
                for (int j = 0; j < matrix[i].size(); j++)
                    matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < matrix[0].size(); i++)
        {
            if (col[i])
            {
                for (int j = 0; j < matrix.size(); j++)
                    matrix[j][i] = 0;
            }
        }
    }
};