#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool sides_fit_hole(float, float, float, float);

int main()
{
	float hole_x, hole_y;
	float brick_a, brick_b, brick_c;

	printf("enter hole dimensions (<space> separated):\n");
	scanf("%f %f", &hole_x, &hole_y);

	printf("enter brick dimensions (<space> separated):\n");
	scanf("%f %f %f", &brick_a, &brick_b, &brick_c);

	if (sides_fit_hole(brick_a, brick_b, hole_x, hole_y)
		|| sides_fit_hole(brick_b, brick_c, hole_x, hole_y)
		|| sides_fit_hole(brick_a, brick_c, hole_x, hole_y))
	{
		cout << "brick fits into hole" << endl;
	}
	else
	{
		cout << "brick doesn't fit into hole" << endl;
	}

	system("pause");
	return 0;
}

bool sides_fit_hole(float side1, float side2, float hole1, float hole2)
{
	return (side1 < hole1 && side2 < hole2) || (side2 < hole1 && side1 < hole2);
}
