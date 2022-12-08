#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n],ansa[n];
    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }
    
    for(int i=0; i<n ; i++)
    {
        ansa[arr[i]] = i;
    }

     for(int i=0 ; i<n ; i++)
    {
        cout<<ansa[i];
    }
    

    return 0;

}