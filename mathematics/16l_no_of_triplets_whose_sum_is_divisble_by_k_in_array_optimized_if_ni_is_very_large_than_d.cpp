#include <iostream>
using namespace std;

int main()
{
    int n, d, count = 0;
    cin >> n >> d;

    int *arr = new int[n];
    int *rem_count = new int[d];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < d; i++)
    {
        rem_count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        rem_count[arr[i] % d]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int k;
            if ((i + j) % d == 0)
            {
                k = 0;
            }
            else
            {
                k = d - (i + j) % d;
            }

            if (k < j)
            {
                continue;
            }

            if (i == j && j == k)
            {
                count += ((rem_count[i]) * (rem_count[i] - 1) * (rem_count[i] - 2)) / 6;
            }
            else if (i == j)
            {
                count += (((rem_count[i]) * (rem_count[i] - 1)) / 2) * rem_count[k];
            }
            else if (j == k)
            {
                count += (((rem_count[j]) * (rem_count[j] - 1)) / 2) * rem_count[i];
            }
            else if (i == k)
            {
                count += (((rem_count[i]) * (rem_count[i] - 1)) / 2) * rem_count[j];
            }
            else
            {
                count += (rem_count[i] * rem_count[j] * rem_count[k]);
            }
        }
    }
    cout << count;

    return 0;
}