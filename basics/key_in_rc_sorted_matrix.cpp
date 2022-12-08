#include <iostream>
using namespace std;

int main()
{
    int key, row, col;
    cin >> key >> row >> col;

    int matrix[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int i = 0, j = col - 1;
    while (!(i >= row || j < 0))
    {
        if (matrix[i][j] == key)
        {
            cout << i << "\t" << j;
            break;
        }
        else if (matrix[i][j] > key)
        {
            j--;
        }
        else if (matrix[i][j] < key)
        {
            i++;
        }
    }
    if (i >= row || j < 0)
    {
        cout << "key not found!";
    }
    return 0;
}

// time complexity row+col;
/*
  //  sample input;
29 4 4
10 20 30 40
15 25 35 45
27 29 37 48
32 33 39 50

*/