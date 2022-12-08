#include <iostream>
using namespace std;
int main()
{
    int n, k, count = 0, max_count = 0, max = 0;

    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            max_count++;
        }
    }

    for (int i = 0; i < max_count; i++)
    {
        if (arr[i] <= k)
        {
            count++;
        }
    }
    max = count;
    for (int i = max_count; i < n; i++)
    {
        if (arr[i] <= k)
        {
            count++;
            if (arr[i - max_count] <= k)
            {
                count--;
            }
        }
        else
        {
            if (arr[i - max_count] <= k)
            {
                count--;
            }
        }

        max = max > count ? max : count;
    }

    cout << max_count - max;

    return 0;
}