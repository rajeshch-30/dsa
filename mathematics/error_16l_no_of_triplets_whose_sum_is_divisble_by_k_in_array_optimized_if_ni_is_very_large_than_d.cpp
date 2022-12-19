// not working need some fixing some flaws are still unresolved

#include <iostream>
using namespace std;

int tempc(int rem_count[], int d, int ign)
{
    int temp_count = 0;

    for (int i = 1 ; i < d / 2 - 1; i++)
    {
        // if (ign != i)
        // {
            temp_count += (rem_count[i]) * (rem_count[d - i]);
        // }
    }

    if ((d) % 2 == 0)
    {
        // if (ign != d/2 && ign != d/2-1)
        // {
            temp_count += ((rem_count[d / 2]) * (rem_count[d / 2] - 1)) / 2;
        // }
    }
    else
    {
        // if (ign != d/2 && ign != d/2+1)
        // {
            temp_count += ((rem_count[d / 2]) * (rem_count[d / 2 + 1]));
        // }
    }
    return temp_count-rem_count[ign];
}

// 10 21
// 34 44 67 45 334 23 45 12 2 7

int main()
{
    int n, d, count = 0;
    cin >> n >> d;

    int *arr = new int[n];
    int *rem_count = new int[d];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < d; i++)
    {
        rem_count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        rem_count[arr[i] % d]++;
    }

    count += ((rem_count[0]) * (rem_count[0] - 1) * (rem_count[0] - 2)) / 6;
    count += (rem_count[0]) * tempc(rem_count, d,0);

    for (int i = 1; i < d; i++)
    {
        count += (rem_count[i]) * tempc(rem_count, d - i,i);
    }

    if ((d) % 2 == 0)
    {
        count += ((rem_count[d / 2]) * (rem_count[d / 2] - 1) * (rem_count[d / 2] - 2)) / 6;
    }
    else
    {
        count += ((rem_count[d / 2]) * ( tempc(rem_count, d / 2 + 1, d/2)));
    }

    cout<<count;
    return 0;
}