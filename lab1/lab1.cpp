#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	const int cn = 2;
	float s_out, s_in;

	cout << "square out = "; cin >> s_out;
	s_in = s_out / cn;

	printf("square in is %d times smaller than square out\n", cn);
	printf("square in = %.2f\n", s_in);

        system("pause");
	return 0;
}
