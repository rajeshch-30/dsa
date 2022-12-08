#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n < 2)
        return 0;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int min = INT_MAX, max = INT_MIN, gap;
    int maxarr[n], minarr[n];

    for (int i = 0; i < n; i++)
    {
        min = min < arr[i] ? min : arr[i];
        max = max > arr[i] ? max : arr[i];
    }

    if (max == min)
    {
        cout << "0";
        return 0;
    }

    gap = (max - min) / (n - 1);
    if ((max - min) % (n - 1) != 0)
    {
        gap++;
    }

    for (int i = 0; i < n; i++)
    {
        maxarr[i] = INT_MIN;
        minarr[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++)
    {
        int bkt = (arr[i] - min) / gap;
        minarr[bkt] = arr[i] > minarr[bkt] ? minarr[bkt] : arr[i];
        maxarr[bkt] = arr[i] > maxarr[bkt] ? arr[i] : maxarr[bkt];
    }

    int ans = INT_MIN, prev = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (minarr[i] == INT_MAX)
        {
            continue;
        }
        if (prev == INT_MIN)
        {
            prev = maxarr[i];
        }
        else
        {
            ans = ans > prev ? ans : minarr[i] - prev;
            prev = maxarr[i];
        }
    }

    cout << ans;

    return 0;
}