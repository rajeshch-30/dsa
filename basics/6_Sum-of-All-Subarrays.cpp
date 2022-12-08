#include <iostream>
using namespace std;
int main() {
    int n;
    long m = 1000000000+7;  // can't use integer
	
	long long sum=0,contribution = 0;
	cin>>n;
	int arr[n];
	for(int i=0 ; i< n; i++)
	{
      cin>>arr[i];
	}
	
	for(int i=0 ; i< n; i++)
	{
	contribution = (((((i+1)%m)*((n-i)%m))%m)%m*(arr[i]%m))%m;
		sum = (sum%m + contribution)%m;
	}
	cout<<sum;
    return 0;
}