#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b == 0)
    {
       return a;
    }

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main()
{
    int n, ans;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ans = gcd(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {

        ans = gcd(ans, arr[i]);
    }

    cout << ans;
}

/*

In this lecture, we will learn how to calculate the GCD of integers stored in an array.

For three numbers ‘a’, ‘b’ and ‘c’,

GCD(a, b, c) = GCD(GCD(a, b), c) = GCD(GCD(a, c), b) = GCD(a, GCD(b, c))

Using the above logic, the GCD of an array ‘Arr[N]’ can be calculated as - 

int GCD = Arr[0];
for(int i = 1; i < N; i++){
     GCD = gcd(GCD, Arr[ i ]);
}

Q. We have been given an integer array ‘Arr[ N ]’. Return ‘1’ if the array contains a subsequence with GCD = 1 otherwise return ‘0’.

Approach:

    Brute Force - Find all the subsequences of the array and calculate their GCD.
    Time complexity: O(2^N)
    For every element we have two options either to select it in the subsequence or not, thus there will be 2^N number of total  subsequences.
    Space complexity: O(1)
    Can we check all the pairs in the array to find if there is any subsequence with GCD = 1?
    No, the above method may not work in every case.
    Eg. For Arr[3] = {6, 10, 15}, GCD(6, 10) = 2; GCD(6, 15) = 3; GCD(10, 15) = 5 but GCD(6, 10, 15) = 1 
    Since we know that the GCD of any number with 1 is 1 itself. Can we use this fact to solve the problem?
    We can calculate the GCD of the entire array and if it is equal to 1, it means the required subsequence exists inside the array, otherwise it doesn’t.
    Time complexity: O(Nlog2(max(Arr[ i ])))
    Space complexity: O(1)
    */