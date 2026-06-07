#include <vector>

using namespace std;

void transposeNaive(
    const vector<vector<int>>& matrix,
    vector<vector<int>>& result)
{
    int n = matrix.size();

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            result[j][i] = matrix[i][j];
        }
    }
}