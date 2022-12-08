#include <iostream>
using namespace std;
int main() {
    int n,k;
	cin >> n >> k;
	long long arr[n];
	
	  k = k%n;   // for very large k , k>>>>n ;
	
	for(int i=0; i<n ; i++)
	{
		cin>>arr[i];
	}
	for(int i=0 ; i< (n-k)/2 ; i++)
	{  
		long long temp = arr[i];
       arr[i]=arr[n-k-i-1];
		arr[n-k-i-1] = temp;
	}
	for(int i=0; i<k/2; i++)
	{
       long long temp = arr[n-k + i];
		arr[n-k+i] = arr[n-1-i];
		arr[n-1-i] = temp;
	}
	
	for(int i =0; i<n/2 ; i++)
	{
       long long temp = arr[i];
		arr[i]=arr[n-1-i];
		arr[n-1-i] = temp;
	}
	
	for(int i=0; i<n ; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	
    return 0;
}