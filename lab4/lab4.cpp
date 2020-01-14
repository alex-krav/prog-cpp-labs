#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main()
{
	int n = 0;
	double sum = 0;

	printf("enter natural number: ");
	scanf("%d", &n);

	for (int k = 1; k <= n; k++)
	{
		sum += 1 / (k*pow((2*k + 1),2));
	}

	printf("sum is %f\n", sum);

	system("pause");
	return 0;
}
