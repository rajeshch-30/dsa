#include <iostream>
using namespace std;

int main()
{
    int n, d, count = 0;
    cin >> n >> d;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if ((arr[i] + arr[j] + arr[k]) % d == 0)
                {
                    count++;
                }
            }
        }
    }

    cout << count;

    return 0;
}