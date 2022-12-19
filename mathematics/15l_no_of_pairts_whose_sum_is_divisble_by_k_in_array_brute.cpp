#include <iostream>
using namespace std;

int main()
{
    int n, k, count = 0;
    cin >> n >> k;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] + arr[j]) % k == 0)
            {
                count++;
            }
        }
    }
    cout << count;

    return 0;
}