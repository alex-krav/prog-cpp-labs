#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int calc_sum(char[]);

int main()
{
	int sum;
	char str[100];

	puts("enter numbers separated with space(s):");
	cin.get(str, 100);

	sum = calc_sum(str);
	printf("Sum is %d\n", sum);

	system("pause");
	return 0;
}

int calc_sum(char str[])
{
	char SPACE = ' ';
	char* delimeter = &SPACE;
	char* p;
	int sum = 0;

	p = strtok(str, delimeter);
	while (p != NULL)
	{
		int current = atoi(p);
		sum += current;
		p = strtok(NULL, delimeter);
	}

	return sum;
}
