#include <vector>
#include <algorithm>

using namespace std;

void transposeTiled(
    const vector<vector<int>>& matrix,
    vector<vector<int>>& result)
{
    int n = matrix.size();

    for(int i = 0; i < n; i += 2)
    {
        for(int j = 0; j < n; j += 2)
        {
            for(int ii = i;
                ii < min(i + 2, n);
                ++ii)
            {
                for(int jj = j;
                    jj < min(j + 2, n);
                    ++jj)
                {
                    result[jj][ii] =
                        matrix[ii][jj];
                }
            }
        }
    }
}