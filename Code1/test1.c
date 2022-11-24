//test.c
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char a = 0b11111101;
//	char c = ((a << 6) >> 7);
	char b = a << 6;
	 b = b >> 7;
	printf("%d",b);
	system("pause");
	return 0;
}


