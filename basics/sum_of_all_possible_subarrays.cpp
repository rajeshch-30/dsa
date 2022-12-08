#include <iostream>
using namespace std;
int sum(int arr[], int i, int j);

int sum(int arr[], int i, int j)
{
    int sum = 0;
    for (int k = i; k <= j; k++)
    {
        sum += arr[k];
    }
    return sum;
}
int main()
{
    int len, sum_sub = 0;

    cout << "Enter length of array : ";
    cin >> len;
    int arr[len];
    cout << "Enter elements of array : ";

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    // pre computation for time complexity Nsquare and space complexity N;
    int pre_comp[len];
    pre_comp[0] = arr[0];
    for (int i = 1; i < len; i++)
    {
        pre_comp[i] = pre_comp[i - 1] + arr[i];
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            // sum_sub += sum(arr,i, j);      // time complexity Ncube
            sum_sub += i > 0 ? pre_comp[j] - pre_comp[i - 1] : pre_comp[j]; // time comlexity N square and space complexity N
        }
    }
    // **********************time complexity N squre and constant space complexity***********************888
    int optimized_sum, ans = 0;
    for (int i = 0; i < len; i++)
    {
        optimized_sum = 0;
        for (int j = i; j < len; j++)
        {
            optimized_sum += arr[j];
            ans += optimized_sum;
        }
    }
    // ******************** Optimization using pnc **************************8
    // ************************* time comlexity N and constant space complexity ********************
    // int ultra_opti_sum = 0;
    // for(int i = 0 ; i < len ; i++){
    //     ultra_opti_sum += arr[i]*(i+1)*(len - i);
    // }
      
      
    // **************** Modular arithematic**************************************
      // m is given in  questio
      int m  = 3;
       int ultra_opti_sum = 0;
       int long long contribution = 0;
    for(int i = 0 ; i < len ; i++){
        ultra_opti_sum = (ultra_opti_sum % m + ((((i+1) % m * (len - i) % m)%m)%m * arr[i]%m)%m) % m;
    }

    cout << sum_sub << endl;
    cout << ans<<endl;
    cout<<ultra_opti_sum;


    return 0;
}

 /*
Lecture 8: Reverse Lookup in 1-Dimenssion

In this lecture, we will learn the application of reverse lookup in a one-dimensional array. Here, we have been given an integer array 'Arr[N]' and we have to find the sum of all its subarrays. 

Approach:

    Brute Force - Create two nested loops to find all the subarrays of array ‘Arr’, followed by another loop to calculate their sum.
    Time complexity: O(N^3)
    Space complexity: O(1)

    Optimised Brute Force - We can simultaneously compute the sum while finding the subarrays of array ‘Arr’.
    Time complexity: O(N^2)
    Space complexity: O(1)

    An array has N(N+1)/2 subarrays, therefore we can not solve this problem in less than O(N2) time complexity if we are trying to find all the subarrays.

    Is there a way to solve it without finding the different subarrays? 

    Using Reverse Lookup - This method insists to think in a reverse manner. Try to think how many times an element will appear if we consider all the subarrays.  

Reverse Lookup in 1D

An element at index i will be a part of all the subarrays whose starting index lies between 0 & i and the ending index lies between i to N-1.

Therefore, using the Rule of Products, the total number of times an element Arr[i] appears = (i + 1)*(N - i).
Total sum = Σ(Arr[i]*(i+1)*(N-i))    [from i=0 to i=N-1]

Time complexity: O(N)
Space complexity: O(1)

Note: The above method involves integer multiplication and the product may go out of the valid integer range. Therefore, we may have to calculate the modulus of the product each time with some large prime number, for example, 10^9 + 7.

*/