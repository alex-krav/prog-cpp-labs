#include <iostream>
#include <stdlib.h>
#include <float.h>
#include <cstdlib>

using namespace std;

float* init_arr(int&);
void print_arr(float*, int);
float* min_max_difference(float*, int);

int main()
{
    float* arr; 
    float* min_max_diff;
    int size;
    
    arr = init_arr(size);
    cout << "Generated array:" << endl;
    print_arr(arr, size);

    min_max_diff = min_max_difference(arr, size);
    cout << "minimum difference = " << min_max_diff[0] << endl;
    cout << "maximum difference = " << min_max_diff[1] << endl;

    system("pause");
    return 0;
}

float* init_arr(int& size)
{
    cout << "set size of array = "; cin >> size;
    float* arr = new float[size];
    
    for (int i = 0; i < size; i++)
    {
        arr[i] = -FLT_MIN + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (FLT_MAX - (-FLT_MIN))));
    }
    
    return arr;
}

void print_arr(float* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

float* min_max_difference(float* arr, int size)
{
    float diff, min = FLT_MAX, max = FLT_MIN;

    for (int i = 0; i < size - 1; i++)
    {
        diff = abs(arr[i] - arr[i + 1]);
        if (min > diff)
        {
            min = diff;
        }
        if (max < diff)
        {
            max = diff;
        }
    }
    
    return new float[2]{ min, max };
}
