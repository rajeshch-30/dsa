#include <iostream>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;

    int arr[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        arr[i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; i*j < n + 1; j++)
        {
            arr[i * j] = arr[i * j] == 1 ? 0 : 1;
            //    cout<<arr[i*j];
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
    }

    cout << count;
    return 0;
}