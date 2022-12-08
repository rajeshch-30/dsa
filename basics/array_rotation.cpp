// time complexity n ; space complexity constant


#include <iostream>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    k = k%n;

    long long arr[n], temp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0 ; i<(n-k)/2 ; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n-k-1-i];
        arr[n-k-1-i] = temp;
    } 


     for(int i = 0 ; i< k/2 ; i++)
    {
        int temp = arr[n-k+i];
        arr[n-k+i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }

    for(int i = 0; i<n/2 ; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout <<arr[i] << "\t";
    }
   



    return 0;
}


/*

// time complexity n ; space complexity n

#include <iostream>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    long long arr[n], temp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        temp[(i+k)%n] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout <<temp[i] << "\t";
    }
    return 0;
}

*/

/*
// time complexity nsquare  ; constant space
#include <iostream>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int j = 0; j < (k % n); j++)
    {
        long long temp = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    return 0;
}

*/