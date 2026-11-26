#include <stdio.h>

void f(int a[10])
{
    printf("%zu\n", sizeof(a) / sizeof(a[0]));
}

int *make(void)
{
    int a[3] = {1, 2, 3};
    return a;
}

int main(void)
{
    /* 1. Какво ще изведе? */
    {
        int a[10];
        printf("%zu\n", sizeof(a) / sizeof(a[0]));
        f(a);
    }

    /* 4. Какъв е проблемът? Защо цикълът може да не спре никога? */
    {
        int i;
        int a[5];
        for (i = 0; i <= 5; i++)
            a[i] = 0;
    }

    /* 6. Ако a е на адрес 0x1000, какви са трите адреса? */
    {
        int a[5];
        printf("%p\n%p\n%p\n", (void *)a, (void *)(a + 1), (void *)(&a + 1));
    }

    /* 7. Какво ще изведе? */
    {
        int a[5] = {1, 2, 3, 4, 5};
        int *p = (int *)(&a + 1);
        printf("%d %d\n", *(a + 1), *(p - 1));
    }

    /* 10. Кой ред се компилира и защо? */
    {
        int a[3] = {1, 2, 3}, b[3];
        // b = a;                       /* (1) */

        struct W { int x[3]; } wa = {{1, 2, 3}}, wb;
        wb = wa;                        /* (2) */
    }

    /* 14. Понякога извежда 2. Защо кодът е грешен? */
    {
        int *p = make();
        printf("%d\n", p[1]);
    }

    return 0;
}
