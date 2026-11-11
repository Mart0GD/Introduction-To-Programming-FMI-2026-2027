#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int       read_number(void);
long long read_numberl(void);
char      read_symb(void);

void t1(void);
void t2(void);
void t3(void);
void t5(void);
void t6(void);
void t9(void);
void t13(void);

int main(void)
{
    t13();
    return 0;
}

/*
*    Задача 1
*    -----
*    Напишете функция, която приема неотрицателно число n и връща обърнатото число.
*/

long long reverse(long long n)
{
    long long reversed = 0;

    while(n != 0)
    {
        reversed *= 10;
        reversed += n % 10;

        n /= 10;
    }

    return reversed;
}

void t1(void)
{
    printf("Insert number: ");
    int number = read_number();
    int reversed = reverse(number);

    printf("The reverse number is: %d\n", reversed);
}

/*
*    Задача 2
*    -----
*    Да се напише програма, която проверява дали дата, зададена в следния формат: dd.mm.yyyy е коректна.
*/

int is_leap(unsigned year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int get_days_in_month(unsigned year, unsigned  month)
{
    unsigned days = 0;

    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: days += 1;

        default: days += 30; break;

        case 2: days = is_leap(year) ? 29 : 28; break;
    }

    return days;
}

void t2(void)
{
    unsigned dd,mm,yyyy;
    int res = 0;

    do
    {
        printf("Insert date: ");
        res = scanf("%u.%u.%u", &dd,&mm,&yyyy);

        int c;
        while((c = getchar()) != EOF && c != '\n');

    } while(res != EOF && res != 3);

    if(res == EOF)
    {
        fprintf(stderr, "Invalid input!");
        exit(1);
    }

    // проверяваме месеца
    if(mm > 12)
    {
        puts("Invalid month!");
        exit(0);
    }

    unsigned days = get_days_in_month(yyyy, mm);

    // проверяваме дните
    if(dd > days)
    {
        printf("Invalid days in month %d. There are %d days but %d was passed\n", mm, days, dd);
        exit(0);
    }

    // проверяваме годината
    if(yyyy > 2026)
    {
        puts("Invalid year, the current year is 2026, can't pass higher!");
        exit(0);
    }

    puts("Valid date!");
}


/*
*    Задача 3
*    -----
*    Напишете функция, която приема неотрицателни числа n и k и връща дали k е суфикс на n.
*/

int is_suffix(int k, int n)
{
    while(k && n)
    {
        int d1 = k % 10;
        int d2 = n % 10;

        if(d1 != d2) break;

        k /= 10;
        n /= 10;
    }

    return k == 0;
}

void t3(void)
{
    int n,k;

    printf("Insert n: ");
    n = read_number();

    printf("Insert k: ");
    k = read_number();

    int suffix = is_suffix(k,n);

    suffix && puts("Suffix!");
    !suffix && puts("Not a suffix!");
}


/*
*    Задача 4
*    -----
*    Напишете функция, която приема неотрицателни числа n и k и връща дали k е префикс на n.
*/

void t4(void)
{
    printf("Insert n: ");
    int n = read_number();

    printf("Insert k: ");
    int k = read_number();

    // Силата на функциите, преизползването...
    int reversed_n = reverse(n);
    int reversed_k = reverse(k);

    int prefix = is_suffix(reversed_k,reversed_n);

    prefix && puts("Prefix!");
    !prefix && puts("Not prefix!");
}

/*
*    Задача 5
*    ----
*    Напишете функция, която приема неотрицателни числа n и k и връща дали k е инфикс на n.
*/

int is_infix(int k, int n)
{
    int tmp = k;

    while(n && k)
    {
        int d1 = k % 10;
        int d2 = n % 10;

        if(d1 == d2) k /= 10;
        else k = tmp;

        n /= 10;
    }

    return k == 0;
}

void t5(void)
{
    printf("Insert n: ");
    int n = read_number();

    printf("Insert k: ");
    int k = read_number();

    int infix = is_infix(k,n);

    infix && puts("Infix!");
    !infix && puts("Not an infix!");
}

/*
*    Задача 6
*    ----
*    Да се дефинира функция, която намира дължината на най-дългия общ префикс/суфикс на два числа.
*/

int suffix_len(int num1, int num2)
{
    int len = 0;
    while(num1 && num2)
    {
        int d1 = num1 % 10;
        int d2 = num2 % 10;

        if(d1 != d2) break;

        num1 /= 10;
        num2 /= 10;
        len++;
    }

    return len;
}


void t6(void)
{
    printf("Insert number 1: ");
    int num1 = read_number();

    printf("Insert number 2: ");
    int num2 = read_number();

    int common_suffix = suffix_len(num1,num2);
    int common_prefix = suffix_len(reverse(num1), reverse(num2));

    printf("Common prefix len: %d\n", common_prefix);
    printf("Common suffix len: %d\n", common_suffix);
}

/*
*    Задача 9
*    ----
*    Да се напише функция, която приема цяло положително число n и отпечатва всички инфикси на n, които са прости, като:
*
*    1) Всяко число е инфикс на себе си;
*    2) Отпечатайте всички инфиски, дори тези, които се повтарят;
*/

int is_prime(int number)
{
    int sr = sqrt((double)number);
    for(int i = 2; i <= sr; ++i)
    {
        if(number % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void t9(void)
{
    printf("Insert number: ");
    int number = read_number();

    // 12345 --> number
    // 5
    // 45
    // 4
    // 345
    // 34
    // 3
    // 2345
    // 234
    // 23
    // 2
    // 12345
    // 1234
    // 123
    // 12
    // 1


    int current = 0;
    int exp = 1;

    while(number != 0)
    {
        current += (number % 10) * exp;

        int tmp = current;
        while(tmp)
        {
            if(is_prime(tmp))
            {
                printf("%d\n", tmp);
            }

            tmp /= 10;
        }

        number /= 10;
        exp *= 10;
    }

}


/*
*    Задача 13
*    ----
*    Напишете функция, която приема число n и връща дължината на най-дългата поредица от последователни растящи цифри в него.
*/

void t13(void)
{
    long long number = read_numberl();

    number = reverse(number);

    int longest_length = 1;
    int current_length = 1;

    int prev = number % 10;
    number /= 10;

    while(number)
    {
        int d = number % 10;

        if(d > prev)
        {
            current_length++;
            longest_length = longest_length > current_length ? longest_length : current_length;
        }
        else current_length = 1;

        prev = d;
        number /= 10;
    }

    printf("Longest increasing subsequence is: %d", longest_length);
}

// ----------------------------------------------------------------
// Помощни функции за четене на вход

int read_number()
{
    int number;
    int res;     // трябва да се дефинира преди цикъла

    do
    {
        /*
        *    Scanf връща:
        *
        *    1) EOF -> край на файл или грешка в четенето
        *    2) Число -> брой на прочетените аргументи
        */
        res = scanf("%d", &number);

        int c;
        while((c = getchar()) != EOF && c != '\n'); // -> чистим потока

    } while (res != EOF && res != 1);

    if(res == EOF)
    {
        fprintf(stderr, "Error reading input!");
        exit(1);
    }

    return number;
}

long long read_numberl()
{
    long long number;
    int res;     // трябва да се дефинира преди цикъла

    do
    {
        /*
        *    Scanf връща:
        *
        *    1) EOF -> край на файл или грешка в четенето
        *    2) Число -> брой на прочетените аргументи
        */
        res = scanf("%lld", &number);

        int c;
        while((c = getchar()) != EOF && c != '\n'); // -> чистим потока

    } while (res != EOF && res != 1);

    if(res == EOF)
    {
        fprintf(stderr, "Error reading input!");
        exit(1);
    }

    return number;
}
