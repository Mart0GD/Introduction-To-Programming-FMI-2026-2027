#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void t1();
void t2();
void t3();
void t4();
void t5();
void t6();
void t7();
void t8();

int main()
{
    t8();
    return 0;
}    

// Задача 1

void t1(void)
{
    int   month;
    int   year;

    puts("Insert month/year");
    int res = scanf("%d/%d", &month, &year);

    if(res != 2)
    {
	puts("Invalid input");
	exit(-1);
    }

    int is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    int days = 0;
    switch(month)
    {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	    days += 1;

	case 4:
	case 6:
	case 9:
	case 11:
	    days += 30;
	break;

        case 2:
	    days = is_leap ? 29 : 28;
    }


    printf("Days: %d\n", days);
}


// Задача 2

void t2()
{
    float n1, n2, n3;

    int res = scanf("%f %f %f", &n1, &n2, &n3);

    if(res != 3)
    {
	puts("Invalid input!");
	exit(-1);
    }

    float first  = n1 <= n2 ? n1 : n2;
    float second = first  == n1 ? n2 : n1;

    float third = n3;

    if(third < second)
    {
	third = second;
	second = n3;
    }
    if(second < first)
    {
	float tmp = first;
	first = second;
	second = tmp;
    }

    printf("Sorted: %.2f %.2f %.2f\n", first, second, third);
}    


// Задача 3
// Да се напише програма, която по зададено **естествено число** намира и извежда римския му запис.
void t3()
{
    int number;
    printf("Insert number: ");

    int res = scanf("%d", &number);

    if(res != 1)
    {
	puts("Invalid input!");
	exit(-1);
    }

    int tens = number / 10;
    int ones = number % 10;

    switch(tens)
    {

	case 8: printf("LXXX"); break;
	case 7: printf("LXX"); break;
	case 6: printf("LX"); break;
	case 5: printf("L"); break;
	case 4: printf("XL"); break;
	case 3: printf("XXX"); break;
	case 2: printf("XX"); break;
	case 1: printf("X"); break;
    }

    switch(ones)
    {
	case 9: printf("IX"); break;
	case 8: printf("VIII"); break;
	case 7: printf("VII"); break;
	case 6: printf("VI"); break;
	case 5: printf("V"); break;
	case 4: printf("IV"); break;
	case 3: printf("III"); break;
	case 2: printf("II"); break;
	case 1: printf("I"); break;
    }
}    

// Задача 4

void t4()
{
    const unsigned int mask = 15; // 1111
    const unsigned int distance_to_mshb = 28;
    
    unsigned int number;
    int res = scanf("%u", &number);
    
    if(res != 1)
    {
	puts("Invalid input!");
	exit(-1);
    }

    unsigned low_hb  = number & mask;
    unsigned high_hb = number >> distance_to_mshb;

    printf("Are the same: %d\n", (low_hb ^ high_hb) == 0);
}    


void t5()
{
    srand(time(NULL));
    
    unsigned int a = 150;
    unsigned int b = 209;

    int max_bit_a = floor(log2((double)a));
    int max_bit_b = floor(log2((double)b));

    int max_bit_value = max_bit_a > max_bit_b ? max_bit_a : max_bit_b;
    int pos = rand() % sizeof(max_bit_value);
    
    unsigned int mask = (1 << pos) - 1;

    unsigned int a_split = a & mask;
    unsigned int b_split = b & mask;

    unsigned int tmp = a_split;
    a_split = a_split ^ a_split | b_split;
    b_split = b_split ^ b_split | tmp;
    
    mask = ~mask;

    a &= mask;
    b &= mask;

    a |= a_split;
    b |= b_split;

    printf("a: %d, b: %d\n", a,b);
}    

void t6()
{
    unsigned int number;

    int res = scanf("%u", &number);
    if(res != 1 || number > 9999)
    {
	puts("Invalid input!");
	exit(-1);
    }

    unsigned int d1 = number % 10;
    unsigned int d2 = (number / 10)   % 10;
    unsigned int d3 = (number / 100)  % 10;
    unsigned int d4 = (number / 1000) % 10;

    unsigned smallest = d1;
    if(d2 < smallest) smallest = d2; 
    if(d3 < smallest) smallest = d3; 
    if(d4 < smallest) smallest = d4;

    unsigned largest = d1;
    if(d2 > largest) largest = d2; 
    if(d3 > largest) largest = d3; 
    if(d4 > largest) largest = d4;

    printf("Biggest difference: %d\n", largest - smallest);
}

void t7()
{
    const unsigned STEP = 10;
    unsigned hh, mm, ss;

    int res = scanf("%u:%u:%u", &hh, &mm, &ss);
    if(res != 3 || hh > 23 || mm > 59 || ss > 59)
    {
	puts("Invalid input!");
	exit(-1);
    }

    int carry_ss = (ss + STEP) / 60;
    ss = (ss + STEP) % 60;

    int carry_minute = (mm + carry_ss) / 60;
    mm = (mm + carry_ss) % 60;

    hh = (hh + carry_minute) % 24;

    printf("%02u:%02u:%02u\n", hh, mm, ss);
}    


/*
## Задача 9 – Точка в триъгълник

Напишете програма, която въвежда координатите на върховете на триъгълник, а след това координатите на точка. Проверете дали точката лежи **в** триъгълника или **извън** него.

**Пример**

```text
Вход:
A: 0 0
B: 5 0
C: 0 5
Point: 1 1

Изход:
The point is inside
```
*/

void t8()
{
    const unsigned eps = 1e-9;
    
    float A_x, A_y;
    float B_x, B_y;
    float C_x, C_y;

    puts("Insert points: ");
    int res = scanf("%f %f %f %f %f %f", &A_x, &A_y, &B_x, &B_y, &C_x, &C_y);

    if(res != 6)
    {
	puts("Invalid input!");
	exit(-1);
    }

    float P_x, P_y;
    printf("Insert point: ");
    res = scanf("%f %f", &P_x, &P_y);

    if(res != 2)
    {
	puts("Invalid input!");
	exit(-1);
    }
           
    /*
            * C
           /|\
          / | \
         / /*\ \
        //  P  \\
     A *---------* B

    */
    

    float
    AP_x = P_x - A_x,
    AP_y = P_y - A_y;

    float
    CP_x = P_x - C_x,
    CP_y = P_y - C_y;

    float
    BP_x = P_x - B_x,
    BP_y = P_y - B_y;
    
    float
    AC_x = C_x - A_x,
    AC_y = C_y - A_y;

    float
    CB_x = B_x - C_x,
    CB_y = B_y - C_y;

    float
    BA_x = A_x - B_x,
    BA_y = A_y - B_y;

    float
    AB_x = B_x - A_x,
    AB_y = B_y - A_y;


    // Проверка за изроден триъгълник (трите точки са на една права) --> ACxAB = 0 (лицето на успоредника е 0)

    float AC_AB_cross = AC_x * AB_y - AC_y * AB_x;

    if(AC_AB_cross <= eps)
    {
	puts("All points are collinear");
	exit(-1);
    }

    // Проверка дали точката е вътре -> трябва знакът на трите произведения да съвпада
    
    float AP_AC_cross = AP_x * AC_y - AP_y * AC_x;
    float CP_CB_cross = CP_x * CB_y - CP_y * CB_x;
    float BP_BA_cross = BP_x * BA_y - BP_y * BA_x;

    int check1 =
    AP_AC_cross > 0 &&
    CP_CB_cross > 0 &&
    BP_BA_cross > 0;
    
    int check2 =
    AP_AC_cross < 0 &&
    CP_CB_cross < 0 &&
    BP_BA_cross < 0;

    if(check1 || check2) puts("Point is inside!");
    else                 puts("Point is outside!");
}    
