#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            int index = arr[i], val = i;
            while (index != i)
            {
                int temp = arr[index];
                arr[index] = -(val + 1);
                val = index;
                index = temp;
            }
            arr[index] = -(val + 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = -arr[i] - 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}