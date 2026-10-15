#include <stdio.h>

int main(void)
{

    double d;
    float  f;
    int    i;

    // ---------- Какво очаквате да стане? ----------


    // // Въпрос 1
    f = 16777216.0f;   // 2^24
    printf("%d\n", f + 1 == f);         // Отговор -> 1 

    // // Въпрос 2
    d = 5 / 9 * (f - 32);
    printf("%d\n", d);                  // Отговор -> 0

    // // Въпрос 3
    printf("%d\n", 0.1 + 0.2 == 0.3);   // Отговор -> 0   

    // Въпрос 4
    i = -7 % 3;
    printf("%d\n", i);                  // Отговор -> -1   

    // Въпрос 5
    f = 6 / 4;
    printf("%f", f);                    // Отговор -> 1 

    // // Въпрос 5

    i = 0;
    (i && 0) && (++i);
    printf("%d", i);                    // Отговор -> 0

}

void t1()
{
    int a, b;
    scanf("%d %d", &a, &b);

    // First method
    int a1 = a;
    int b1 = b;

    a = b1;
    b = a1;

    // Second method
    int atemp = a;

    a = b;
    b = atemp;

    // Third method
    a = a + b;
    b = a - b;
    a = a - b; 
}

void t3()
{
    int side1, side2, side3;

    scanf("%d %d %d", &side1, &side2, &side3);

    int res = 
    side1 + side2 >= side3 &&
    side2 + side3 >= side1 &&
    side3 + side1 >= side2;
}

void t4()
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    int positive = (a > 0) + (b > 0) + (c > 0);
    int negative = 3 - positive;

    printf("Postive: %d, Negative: %d", positive, negative);
}

void t5()
{
    int x1, y1;
    int x2, y2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int dx = ((x1 - x2) > 0) * (x1 - x2) + !((x1 - x2) > 0) * (x2 - x1);
    int dy = ((y1 - y2) > 0) * (y1 - y2) + !((y1 - y2) > 0) * (y2 - y1);

    int tower = x1 == x2 || y1 == y2;
    int bishop = dx == dy;
    int queen = tower || bishop;
    int knight = (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    int king = dx <= 1 && dy <= 1;
}