#include <stdio.h>
#include <stdlib.h>
struct  student_s
{
 char name[10];
 int chinese;
};


int main()
{
    struct student_s a;
    a.chinese = 5;
    printf("%d",a.chinese);
    system("pause");
    return 0;

}

