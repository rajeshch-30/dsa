#include <iostream>
using namespace std;
int main()
{
    int n, ans = 0;
    cin >> n;

    // int *arr = new int(n);
    // int *pre_max = new int(n);

    int arr[n], pre_max[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    pre_max[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pre_max[i] = pre_max[i - 1] > arr[i] ? pre_max[i - 1] : arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (pre_max[i] == i)
        {
            ans++;
        }
    }
    // free(arr);
    // free(pre_max);
    cout << ans;

    return 0;
}