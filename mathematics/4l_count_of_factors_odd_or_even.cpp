#include <iostream>
#include<cmath>

using namespace std;
int main()
{
  int n;
  cin>>n;
   int sq = sqrt(n);

   if(sq*sq == n)
   {
      cout<<"odd";
   }
   else
   {
    cout<<"even";
   }


  return 0;
}

/*
Note: If an integer is a perfect square then it has an odd number of factors otherwise it will have an even number of factors.
*/