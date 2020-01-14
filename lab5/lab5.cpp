#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

float my_ln(float);

using namespace std;

int main()
{
	float arg;
	printf("enter 0 <= x <= 2: ");
	scanf("%f", &arg);

	printf("my_ln %f is %f\n", arg, my_ln(arg));
	printf("ln %f is %f\n", arg, log(arg));

    system("pause");
	return 0;
}

float my_ln(float x)
{
	const float eps = 1e-6;
    float ans = 1;
    float sum = -1;
	int k = 0;

    while (fabs(ans) > eps) 
    {
        sum += ans;
        k++;
		ans = (-1) * pow(-1, k) * pow((x - 1), k) / k;
	}

	return sum;
}
