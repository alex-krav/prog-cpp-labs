#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

int** init_arr(int&);
void print_arr(int**, int);
int** draw_diagonals(int**, int);

int main()
{
    int** in_arr; 
    int** out_arr;
    int N;
    
    in_arr = init_arr(N);
    cout << "Your array:" << endl;
    print_arr(in_arr, N);

    out_arr = draw_diagonals(in_arr, N);
    cout << "Array after changes:" << endl;
    print_arr(out_arr, N);

    system("pause");
    return 0;
}

int** init_arr(int& size) 
{
    cout << "Rows/Columns = "; cin >> size;
    int** arr = new int* [size];

    // init array
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[size];
    }

    // fill with generated values
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }

    return arr;
}

void print_arr(int** arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int** draw_diagonals(int** arr, int size) {

    int n, m;
    cout << "Set element [row][column]" << endl;
    cout << "Row = "; cin >> n;
    cout << "Column = "; cin >> m;
    int l = m, r = m;
    int max = INT_MIN;

    // init new array
    int** new_arr = new int* [size];
    for (int i = 0; i < size; i++)
    {
        new_arr[i] = new int[size];
    }

    // find max element
    for (int i = n; i < size; i++)
    {
        for (int j = 0; j < size; j++)
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
    for (int i = 0; i < size; i++)
    {
        if (i >= n)
        {
            for (int j = 0; j < size; j++)
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
            for (int j = 0; j < size; j++)
            {
                new_arr[i][j] = 0;
            }
        }
    }

    return new_arr;
}
