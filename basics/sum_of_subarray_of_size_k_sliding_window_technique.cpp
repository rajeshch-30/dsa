#include <iostream>
using namespace std;

int main()
{
    long long n, k, sum = 0;
    cin >> n >> k;

    long long arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    for (int i = k; i < n; i++)
    {
        cout << sum<<"\t";
        sum += arr[i] - arr[i - k];
    }
    cout<<sum<<"\t";

    return 0;
}