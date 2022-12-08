#include <iostream>
using namespace std;

int chunked(int arr[], int i, int j)
{
    int count = 0;
    for (int k = i; k <= j; k++)
    {
        if ((i <= arr[k]) && (arr[k] <= j))
        {
            count++;
        }
    }
    return count == j - i + 1 ? 1 : 0;
}

int main()
{
    int len, ans = 0;
    cout << "Enter length of array : ";
    cin >> len;

    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
        if (arr[i] >= len)
            cout << "Invalid input!";
    }

    for (int i = 0; i < len; i++)
    {
        int j;
        for (j = i; j < len; j++)
        {
            if (chunked(arr, i, j))
            {
                break;
            }
        }
        i = j;
        ans++;
    }
    cout << ans;
}