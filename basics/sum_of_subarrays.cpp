#include<iostream>
using namespace std;

int main()
{
    long long n,sum=0;

    cin>>n;

    long long arr[n];

    for(int i=0 ; i<n ; i++)
    {
       cin>>arr[i];
    }
    
    for(int i=0 ; i<n; i++)
    {
        sum += (i+1)*(n-i)*arr[i];
    }

    cout<<sum;


    return 0;
}