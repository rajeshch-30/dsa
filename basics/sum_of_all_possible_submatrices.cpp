#include <iostream>
using namespace std;

// template<size_t row,size_t col>
int brute_sum(int **matrix, int ltr, int ltc, int rbr, int rbc)
{
    int sum = 0;
    for (int i = ltc; i <= rbc; i++)
    {
        for (int j = ltr; j <= rbr; j++)
        {
            sum += *(*(matrix + i) + j); // matrix is just like linear array with extra information about column to skip space.
            cout << sum << endl;
            // cout << "chaska";
        }
    }
    return sum;
}

int main()
{
    int row, col, sum1 = 0;

    cout << "Enter order of matrix : \n"
         << "row : ";
    cin >> row;
    cout << "column : ";
    cin >> col;

    // int **matrix;
    // matrix = new int *[row];
    int matrix[row][col];

    cout << "Enter elements of matrix row wise : ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //          cout<<*(*(matrix + i) + j);
    //     }
    // }
    // *************** Brute force (time complexity N pow 6 and constant space complexity)*******************
    for (int ltr = 0; ltr < row; ltr++)
    {
        for (int ltc = 0; ltc < col; ltc++)
        {
            for (int rbr = ltr; rbr < row; rbr++)
            {
                for (int rbc = ltc; rbc < col ; rbc++)
                {
                    // sum += brute_sum(matrix, ltr, ltc, rbr, rbc); //  // tycasted matrix into integer pointer.
                    // cout<<sum;
                    // cout<<"dno";
                    int sum = 0;
                    for (int i = ltr; i <= rbr; i++)
                    {
                        for (int j = ltc ; j <= rbc; j++)
                        {
                            sum += matrix[i][j] ;// matrix is just like linear array with extra information about column to skip space.
                            // cout << sum << endl;
                            
                            // cout << "chaska";
                        }
                    }
                    sum1+=sum;
                }
            }
        }
    }
    cout << sum1;
    // cout << "dne";

    return 0;
}