#include <stdio.h>
#include <stdlib.h>

int Largest_common_divisor(int m, int n);//寻找最大公约数
int Least_common_multiple(int m, int n);//寻找最小公倍数

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d\n%d", Largest_common_divisor(m, n), Least_common_multiple(m, n));
	system("pause");
    return 0;
}


int Largest_common_divisor(int m, int n)
{
    int small_num = m < n ? m : n;
    for (int i = small_num; i > 0; i--)
    {
        if (m % i == 0 && n % i == 0)
            return i;
    }
}

int Least_common_multiple(int m, int n)
{
    int large_num = m > n ? m : n;
    for (int i = large_num; ; i++)
    {
        if (i % m == 0 && i % n == 0)
            return i;
    }
}
