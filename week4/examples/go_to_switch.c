#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    if (n == 1) goto case1;
    if (n == 2) goto case2;
    if (n == 3) goto case3;
    goto default_;          // нито един case не съвпадна

case1:
    puts("Inside case 1");
    goto end;               // break;

case2:
    puts("Inside case 2");
    goto end;               // break;

case3:
    puts("Inside case 3");
    goto end;               // break;

default_:
    puts("Inside default");
    /* последният етикет няма нужда от goto end */

end:
    return 0;
}
