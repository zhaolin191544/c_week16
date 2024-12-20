#include <stdio.h>
#include <ctype.h>  

int isNumber(const char *str) {
    if (str == NULL || *str == '\0') {
        return -1;  
    }

    int num = 0;
    int sign = 1;  

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    while (*str) {
        if (!isdigit(*str)) {
            return -1;  
        }
        num = num * 10 + (*str - '0');
        str++;
    }

    return num * sign;  
}

int main() {
    int t;
    scanf("%d", &t);  
    while (t--) {
        char str[100];  
        scanf("%s", str);  

        int result = isNumber(str);
        printf("%d\n", result);  
    }
    return 0;
}
