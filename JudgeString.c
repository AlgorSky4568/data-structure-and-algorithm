#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(void)
{

    char a[800], b[800];
    scanf("%[^\n]%*c", a);
    scanf("%[^\n]%*c", b);

    // 直接使用strstr函数
    if (strstr(a, b) != NULL)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}
