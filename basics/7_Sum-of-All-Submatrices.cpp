#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    long long sum = 0, contribution = 0, mod = 1000000000 + 7;

    long matrix[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp_contribution = (((((i + 1) % mod) * ((n - i) % mod)) % mod) % mod * (matrix[i][j] % mod)) % mod;
            contribution = (((((j + 1) % mod) * ((m - j) % mod)) % mod) % mod * (temp_contribution) % mod) % mod;
            sum = (sum % mod + contribution % mod) % mod;
        }
    }

    cout << sum;
    return 0;
}