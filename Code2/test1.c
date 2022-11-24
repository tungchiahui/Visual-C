//test.c
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,a[5],*p = a;
	for(i=0;i<5;i++){
		printf("请输入第%d个数字:",i+1);
    	scanf("%d",p++);
    }
		p=a; //相当于p=&a[0]
	for(i=0;i<5;i++,p++){
    	printf("第%d个数字为：%d\n",i+1,*p); 
    }
	system("pause");
	return 0;
}
