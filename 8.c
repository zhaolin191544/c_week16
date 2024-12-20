#include <stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 10

//请补充itostr函数的实现
void itostr(int num, char str[])
{

    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    int flag = 0, sign = 1;
    if (num < 0) {
        str[0] = '-';
        flag = 1;
        sign = -1;
    }
    int _num = num, count = 0;
    while(_num) {
        _num /= 10;
        count++;
    }
    str[count + flag] = '\0';
    if (num / 10)
        itostr(num / 10, str);
    str[count - 1 + flag] = sign * num % 10 + '0';

}

int main()
{
    int t,num;
    char str[SIZE];

    scanf("%d",&t);
    while(t--)
    {
     	memset(str, '0', sizeof(str));
        scanf("%d", &num);
        itostr(num,str);
        printf("%s\n",str);
    }
}