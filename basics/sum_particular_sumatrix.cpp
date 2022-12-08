#include <iostream>
using namespace std;

int main()
{
    int m, n, sum = 0;
    cin >> m >> n;

    int matrix[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;

    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {

            matrix[i][j] += matrix[i][j - 1];
        }
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i < m; i++)
        {
            matrix[i][j] += matrix[i - 1][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i1 - 1 < 0 && j1 - 1 < 0)
            {
                sum = matrix[i2][j2];
            }
            else if (j1 - 1 < 0)
            {
                sum = matrix[i2][j2] - matrix[i1 - 1][j2];
            }
            else if (i1 - 1 < 0)
            {
                sum = matrix[i2][j2] - matrix[i2][j1 - 1];
            }
            else
            {
                sum = matrix[i2][j2] - matrix[i2][j1 - 1] - matrix[i1 - 1][j2] + matrix[i1 - 1][j1 - 1];
            }
        }
    }

    cout << sum;

    return 0;
}