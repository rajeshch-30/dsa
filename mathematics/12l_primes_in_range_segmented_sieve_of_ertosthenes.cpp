#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int l, r;
    cin >> l >> r;

    int sq = sqrt(r); // sq should be less than 10^6;
    int primes[sq + 1];

    for (int i = 1; i < sq + 1; i++)
    {
        primes[i] = 1;
    }

    primes[1] = 0;
    for (int i = 2; i * i <= sq; i++)
    {
        if (primes[i] == 1)
        {
            for (int j = i; i * j <= sq; j++)
            {
                primes[i * j] = 0;
            }
        }
    }

    vector<int> isprime;
    for (int i = 1; i <= sq; i++)
    {
        if (primes[i] == 1)
        {
            isprime.push_back(i);
        }
    }
    // -------------------------------------------------------------------
    //    for(int i = 0 ;i< isprime.size() ; i++)
    //    {
    //       cout<<isprime[i]<<" ";
    //    }

    // -------------------------------------------------------------------

    vector<bool> ans(r - l + 1, true);
    for (int i = 0; i <= isprime.size(); i++)
    {
        int k = ceil((l * 1.0) / isprime[i]);
        for (int j = max(k, 2); (isprime[i]) * j <= r; j++)
        {
            ans[isprime[i] * j - l] = false;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == true)
        {
            cout << l + i << " ";
        }
    }
    return 0;
}

/*

 limitation of the Sieve of Eratosthenes in finding primes in the range [L, R] where  L~10^9 and (R-L) is small.

Print all the primes in the range [L, R] such that L = 10^10, R=10^10+500.

Using Segmented Sieve:
The major drawback of the sieve of Eratosthenes is the space taken by the auxiliary array. Can we somehow reduce the extra space? 

    Consider that we have an array representing the state of numbers between L & R. Then what will be the required prime numbers to strike off the composites in [L, R]?
    => Primes between 2 to √R

    For example, For L = 90 & R = 99, the prime numbers between 2 to √99(~10) are sufficient to strike off all the composites.
    90  91  92  93  94  95  96  97  98  99

    Numbers divisible by 2
    90  91  92  93  94  95  96  97  98  99

    Numbers divisible by 3 out of the remaining numbers
    91  93  95  97  99

    Numbers divisible by 5 out of the remaining numbers
    91  95  97

    Numbers divisible by 7 out of the remaining numbers
    91  97

    Primes found: 97
    Since we are able to achieve our objective by using prime numbers till √R. Therefore there is no need to find the state of all the numbers from 1 to R. 
    We can use the Sieve of Eratosthenes to find the prime numbers between 1 to √R and can store them in a vector P[ ]. It will help in making the process of striking more efficient by removing the composites between 1 to √R.
    Time complexity: O(√Rloglog√R)
    Space complexity: O(√R)
    Create a boolean array isPrime[ ] of size (R-L+1) to track the state of numbers in [L, R] and mark them as prime initially. 
    Iterate on the primes array P[ ] and strike out their divisors by marking them as non-prime in the isPrime[ ] array.
    The first multiple of prime P[i] in the range [L,R] can be found as P[i]*k where k = ceil((L*1.0)/P[i])

Note: 

    ceil() returns the Greatest Integer close to the decimal value inside it.
    ceil(3.2) = 4
    ceil(3.0) = 3
    floor(3.2) = 3
    floor(3.0) = 3
    L/P[i] results in an integer division therefore we multiply L with 1.0 for a float division.
*/

//----------------------------------------------------------------------------------------------------------------------------------------

/*

Find prime numbers in the range [Li, Ri] for the given ‘Q’ queries - (L1, R1), (L2, R2), (L3, R3)....(Lq, Rq) & R<=10^11.

Code:

//Extracting primes between 1 to √R(~10^6)

vector<int> getPrimes( ){
     vector<bool> isPrime(10^6+1, true);  //labeling numbers till √R as prime(true)
     isPrime[1] = false;
     for(int i = 2; i*i<=10^6; i++){
           if(isPrime[i]){   //Iterating to strike multiples of prime no. ‘i’
              for(int j = i*i; j<=10^6; j+=i){
                    isPrime[j]=false;  //marking non-primes as false  
}
           }
       }
       vector<int> primes;
       //storing all the prime numbers in a vector - primes[ ]
       for(int i =1; i<10^6; i++){
             if(isPrime[i]){
                primes.push_back(i);
             }
        }
}

//finding primes in the range [L, R]

//labeling numbers in [L, R] as prime(true)
vector<bool> isPrime(R-L+1, true)

//iterating over the primes array to strike off their multiples in [L, R]
for(int i = 0; i<primes.size(); i++){
     int k = ceil((L*1.0)/primes[i]);
     if(k<2)k++;
     //if primes[i]>L, then k=1 & primes[i]*k will be the prime itself, therefore we ensure that k>=2  
for(int j = k; primes[i]*j<=R; j++){
          isPrime[primes[i]*j-L] = false;  //marking composite numbers as false
     }
}

//iterate ‘Q’ times to print the primes in the range [Li, Ri]

Time complexity: O(√Rloglog√R + (R - L)(loglog√R))
Space complexity: O(√R)*/