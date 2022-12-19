#include <iostream>
#include<cmath>

using namespace std;
int main()
{
  int n;
  cin>>n;
   int sq = sqrt(n);

   for(int i=1; i<=sq; i++)
   {
      if(n%i == 0)
      {
        if(i*i == n)
        {
          cout<<i;
        }
        else
        {
        cout<<i<<" "<<n/i<<" ";
        }
      } 
   }

 return 0;
}

/*

Factors of a number ‘a’ are all the different numbers that divide ‘a’.
Eg. Factors of 12 = {1, 2, 3, 4, 6, 12}

Approach:

    Brute Force - Iterate from 1 to N and check if they divide N or not.
    Time complexity: O(N)
    Optimised Brute Force - Since the factors of ‘N’ are symmetric about its square root ie √N. 

Factors of a number are symmetric around its square root

Therefore, we can iterate from 1 to √N. And if ‘i’ divides N, it means both ‘i’ and ‘N/i’ are the factors of N excluding the case where i=N/i or i =√N - to avoid duplication while printing.
Time complexity: O(√N)

Note: If an integer is a perfect square then it has an odd number of factors otherwise it will have an even number of factors.
*/