#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int calc_sum(char[]);

int main()
{
	int sum;
	char str[100];

	puts("enter numbers separated with space(s):");
	gets_s(str);

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
	char* np = NULL;
	int sum = 0;

	p = strtok_s(str, delimeter, &np);
	while (p != NULL)
	{
		int current = _strtoi64(p, NULL, 10);
		sum += current;
		p = strtok_s(NULL, delimeter, &np);
	}

	return sum;
}
