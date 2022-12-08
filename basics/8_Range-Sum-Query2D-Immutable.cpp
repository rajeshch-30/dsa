#include <iostream>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m;
    long long sum = 0;

    int matrix[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {

            matrix[i][j] += matrix[i][j - 1];
        }
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = 1; i < n; i++)
        {
            matrix[i][j] += matrix[i - 1][j];
        }
    }

    cin >> q;
    int i1, j1, i2, j2;
    for (int i = 0; i < q; i++)
    {
        cin >> i1 >> j1 >> i2 >> j2;

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

        cout << sum << "\n";
    }

    return 0;
}