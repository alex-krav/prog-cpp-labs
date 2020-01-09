#include <iostream>
#include <stdlib.h>

using namespace std;

int** init_arr(int&, int&);
void print_arr(int**, int, int);
int** draw_diagonals(int**, int, int);

int main()
{
    int** in_arr; 
    int** out_arr;
    int C, R;
    
    in_arr = init_arr(C, R);
    cout << "Your array:" << endl;
    print_arr(in_arr, C, R);

    out_arr = draw_diagonals(in_arr, C, R);
    cout << "Array after changes:" << endl;
    print_arr(out_arr, C, R);

    system("pause");
    return 0;
}

int** init_arr(int& columns, int& rows) 
{
    cout << "Rows = "; cin >> columns;
    cout << "Columns = ";  cin >> rows;
    int** arr = new int* [rows];

    // init array
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[columns];
    }

    // fill with generated values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = rand() % 9;
        }
    }

    return arr;
}

void print_arr(int** arr, int colums, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int** draw_diagonals(int** arr, int columns, int rows) {

    int n, m;
    cout << "Set element [row][column]" << endl;
    cout << "Row = "; cin >> n;
    cout << "Column = "; cin >> m;
    int l = m, r = m;
    int max = INT_MIN;

    // init new array
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        new_arr[i] = new int[columns];
    }

    // find max element
    for (int i = n; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (j >= l && j <= r)
            {
                if (max < arr[i][j])
                {
                    max = arr[i][j];
                }
            }
        }
        l--; r++;
    }

    // fill new array with zeros and max 
    l = m, r = m;
    for (int i = 0; i < rows; i++)
    {
        if (i >= n)
        {
            for (int j = 0; j < columns; j++)
            {
                if (j >= l && j <= r)
                {
                    new_arr[i][j] = max;
                }
                else
                {
                    new_arr[i][j] = 0;
                }
            }
            l--; r++;
        }
        else
        {
            for (int j = 0; j < columns; j++)
            {
                new_arr[i][j] = 0;
            }
        }
    }

    return new_arr;
}
