#include <stdio.h>

void geometry_task1()
{
    float big_circle_x = 0, big_circle_y = 0;
    float small_circle1_x = -1, small_circle1_y = 0;
    float small_circle2_x = 1,  small_circle2_y = 0;

    float big_r = 2;

    float p_x, p_y;
    scanf("%f %f", &p_x, &p_y);

    float dist_to_big_circle   = (p_x - big_circle_x) * (p_x - big_circle_x) + (p_y - big_circle_y) * (p_y - big_circle_y);
    float dist_to_small_circle1 = (p_x - small_circle1_x) * (p_x - small_circle1_x) + (p_y - small_circle1_y) * (p_y - small_circle1_y);
    float dist_to_small_circle2 = (p_x - small_circle2_x) * (p_x - small_circle2_x) + (p_y - small_circle2_y) * (p_y - small_circle2_y);

    int check1 = dist_to_small_circle1 <= 1;
    int check2 = dist_to_big_circle <= (big_r * big_r) && p_y >= 0;
    int check3 = dist_to_small_circle2 > 1;

    int inside = (check1 && check2) && check3;

    inside  && puts("Inside!");
    !inside && puts("Outside!");
}   


int geometry_task2()
{
    int p_x = -2, p_y = 0;

    scanf("%d %d", &p_x, &p_y);
    
    float v1_x = -3, v1_y = 4;   
    float v2_x = 3,  v2_y = 6; 

    float vp_x = p_x + 2;
    float vp_y = p_y + 1;

    float dist_to_small_circle = (p_x + 1) * (p_x + 1) + (p_y - 4) * (p_y - 4);
    float dist_to_big_circle = vp_x * vp_x + vp_y * vp_y;

    // Искаме да са положителни векторните произведения
    float cross_v2_vp = v2_x * vp_y - v2_y * vp_x;
    float cross_vp_v1 = vp_x * v1_y - vp_y * v1_x;

    int res = dist_to_small_circle > 1
           && dist_to_big_circle <= 45
           && cross_v2_vp >= 0
           && cross_vp_v1 >= 0;

    printf("Result: %d\n", res);
    return 0;
}


// Степен на 2-ка
void t3()
{
    unsigned int power;

    scanf("%u", &power);
    printf("%u", 1 << power);
}    

// Дали е степен на 2-ка
void t4()
{
    unsigned int number;

    scanf("%u", &number);
    printf("%d", number != 0 && (number & (number - 1)) == 0);
}

// k-th bit
void t5()
{
    unsigned int number;
    unsigned int k;
    
    scanf("%u %u", &number, &k);

    int bit = (number & (1 << k)) >> k;
    printf("%d", bit);
}    

// размяна на числа
void t6()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    num1 ^= num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;

    printf("Number 1: %d, Number 2: %d", num1, num2);
}

// flip, turn off/on
void t7()
{
    unsigned int num;
    unsigned int i, j, k;

    scanf("%u", &num);
    printf("Enter i,j,k");
    scanf("%u %u %u", &i, &j, &k);

    // turn off
    num = num & ~(1 << i);

    // turn on
    num = num | (1 << j);

    // switch
    num = num ^ (1 << k);

    printf("Number: %u", num);
}    

