#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int a[5], * p = a;
	int i = 1;
	while (i < 6)
	{
		printf("请输入第%d个数字:", i);
		scanf_s("%d", &a);
			i++;
	}
	
	int j = 1;
	while (j < 6) {
		printf("第%d个数字为:%d\n", j, *p);
		j++;
		p++;
	}
	system("pause");
	return 0;
}