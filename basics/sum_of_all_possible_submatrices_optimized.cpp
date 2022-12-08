#include<iostream>
using namespace std;

int main()
{
    int m,n,sum=0;
    cin>>m>>n;

    int matrix[m][n];

    for(int i = 0 ; i < m ; i++)
    {
        for(int j=0; j < n ; j++)
        {
            cin>>matrix[i][j];
        }
    }
    
     for(int i = 0 ; i < m ; i++)
    {
        for(int j=0; j < n ; j++)
        {
            sum +=(i+1)*(j+1)*(m-i)*(n-j)*matrix[i][j];
        }
    }

    cout<<sum;
    

    return 0;
}