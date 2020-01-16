#include <iostream>
#include <stdlib.h>

using namespace std;

void print_dividends(int, int, int);

int main()
{
	print_dividends(22200, 22299, 15);

	system("pause");
	return 0;
}

void print_dividends(int start, int end, int divider)
{
	for (int i = start; i <= end; i++)
	{
		if (i % divider == 0)
		{
			cout << i << endl;
		}
	}
}