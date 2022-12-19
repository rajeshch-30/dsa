#include <iostream>
// #include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool primes[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        primes[i] = true; // assumed all numbers are prime
    }

    primes[1] = false;
    for (int i = 2; i * i <= n; i++) // used to avoid use of cmath library
    {
        if (primes[i] == 1)
        {
            for (int j = i; i * j <= n; j++)
            {
                primes[i * j] = false;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (primes[i] == 1)
        {
            cout << i << " ";
        }
    }

    return 0;
}

/*

implementation of the sieve of Eratosthenes.

bool Primes[N+1];             //To store the nature of all the numbers from 1 to N
for(int i = 1; i<N+1; i++){
     Primes[i]=1;                 //All the numbers are marked as Primes
}
Primes[0]=0;                   //Non-primes are represented by 0
for(int i = 2; i*i<=N; i++){
     if(Primes[i]==1){        //If a number is prime then mark its multiples as non-prime
        for(int j=i*i;j<=N;j+=i){
              Primes[j]=0;    
         }
      }
}

Drawback:

If we have to find the prime numbers in the range - 10^9 to 10^10. Then this approach may not be helpful because the space required by the boolean array will not fit in the memory of the program. For such cases, the brute force approach of O(N√N) will be a better choice.
*/