#include <iostream>
#include<climits>
using namespace std;

int main()
{
    int len;
    int P, Q, R, max_chunk =INT_MIN;
    cout << "length of array : ";
    cin >> len;
    int arr[len], prefix_max[len], suffix_max[len];
    cout << "entries of array : ";
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    cout << "enter P Q R :";
    cin >> P >> Q >> R;

    prefix_max[0] = P*arr[0];
    for (int i = 1; i < len; i++)
    {
        prefix_max[i] = P*arr[i] > prefix_max[i - 1] ?P* arr[i] : prefix_max[i - 1];
    }

    suffix_max[len - 1] = R*arr[len - 1];
    for (int i = len - 2; i >= 0; i--)
    {
        suffix_max[i] =R * arr[i] > suffix_max[i + 1] ? R*arr[i] : suffix_max[i + 1];
    }

    int temp_chunk = 0;
    for (int i = 1; i < len - 1; i++)
    {
        temp_chunk = prefix_max[i - 1] + Q * arr[i] + suffix_max[i + 1];
        max_chunk = max_chunk > temp_chunk ? max_chunk : temp_chunk;
    }
    cout << max_chunk;

    return 0;

    // time and space complexity in N;
}


/*
In this lecture, we will look at another problem based on the pre-computation technique. Here, we have been given an array ‘Arr[N]’ and we have to maximise ‘s’
s = p*Arri + q*Arrj + r*Arrk where p, q, r ∈ Z and i < j < k

Approach:

    Brute force - Run three nested loops to find the sum of all possible combinations and hence the maximum value of ‘s’.
    Time Complexity: O(N^3)
    Space Complexity: O(1)

    How about choosing the first three largest elements to calculate ‘s’?
    No, it may not work since we are not dealing with positive numbers alone. Let us see an example -
    Arr[5] = { 1, 2, 3, 4, -5}, p = 1, q = 2, r = -3
    According to the above approach,
    s = 1(2) + 2(3) + (-3)(4) = -4, which is not the correct answer.

    What if we know all the three maximum terms separately?
    Let a = p*Arri, b = q*Arrj and c = r*Arrk. If we can fix the second term (b) and find the maximum possible value of a & c corresponding to that b. And if we repeat the process for all the possible values of b then we can easily find the maximum value of ‘s’.

    For implementing this, we can create a prefix max(PMAX) and a suffix max(SMAX) array for the first and the third term respectively. We can then iterate on the array for the second term to find the answer.

    ans = max (ans, PMAX[j-1]+q*Arr[j]+SMAX[j+1])

    Time complexity: O(N)
    Space complexity: O(N) 
*/