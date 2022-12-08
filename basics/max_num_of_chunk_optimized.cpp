#include <iostream>
using namespace std;

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

    int pre_max[len];
    pre_max[0] = arr[0];
    for (int i = 1; i < len; i++)
    {
        pre_max[i] = pre_max[i - 1] < arr[i] ? arr[i] : pre_max[i - 1];
    }

    for (int i = 0; i < len; i++)
    {
        if (pre_max[i] <= i)
        {
            ans++;
        }
    }
    
    cout << ans;
    return 0;
}