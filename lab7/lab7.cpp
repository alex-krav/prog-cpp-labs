#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <float.h>

using namespace std;

float* calc_squares(int);
bool triangle_sides_correct(float, float, float);
float square(float, float, float);
int find_max_square_index(float*, int);

int main()
{
	const int THREE = 3;
	float* squares;
	int max_index;

	squares = calc_squares(THREE);
	if (squares != NULL) 
	{
		max_index = find_max_square_index(squares, THREE);
		printf("Triangle %d has maximum square %0.2f\n", max_index, squares[max_index]);
	}

	system("pause");
	return 0;
}

float* calc_squares(int size) 
{
	float a, b, c;
	float* squares = new float[size];

	for (int i = 0; i < size; i++)
	{
		printf("Enter side lengths for triangle %d (<space> separated):\n", i);
		scanf_s("%f %f %f", &a, &b, &c);
		if (!triangle_sides_correct(a, b, c))
		{
			printf("Side lengths are incorrect\n");
			return NULL;
		}
		squares[i] = square(a, b, c);
	}

	return squares;
}

bool triangle_sides_correct(float a, float b, float c)
{
	if ((a + b > c) && (a + c > b) && (b + c > a)) 
	{
		return true;
	} 
	else 
	{
		return false;
	}
}
float square(float a, float b, float c)
{
	float p = a + b + c;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

int find_max_square_index(float* squares, int size)
{
	float max = FLT_MIN;
	int index = -1;

	for (int i = 0; i < size; i++) {
		if (max < squares[i])
		{
			max = squares[i];
			index = i;
		}
	}

	return index;
}
