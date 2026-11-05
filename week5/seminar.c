#include <stdio.h>
#include <stdlib.h>

// числа с фиксиран размер
#include <stdint.h> 
#include <inttypes.h>
#include <math.h>

void t1(void);
void t2(void);
void t3(void);
void t4(void);
void t5(void);
void t6(void);
void t7(void);
void t8(void);
void t9(void);

int main(void)
{
    t9();
    return 0;
}    


/*
* Задача 1
* ----
*
* Напишете програма, която по подадено 16-битово число n извежда на конзолата
* представянето му в двоична бройна система.

* Направете и обратната задача: по подадено n в двоична го принтирайте в десетична*
*/

void t1(void)
{
    uint64_t number;
    int32_t res = scanf("%" SCNu64, &number);

    if(res != 1)
    {
	fprintf(stderr, "Invalid input!");
	exit(-1);
    }

    // Десетична в двоична 
    for(int32_t i = sizeof(uint16_t) * 8 - 1; i >=0; --i)
    {
	// Ако битът е нула, цялото число става 0!
	int32_t digit = (number & (1 << i)) != 0;
	printf("%" PRId16, digit);
    }

    puts("");
    
    // Двоична в десетична (Максимумът ни е 20 единици)

    number;
    scanf("%" SCNu64, &number);

    uint64_t sum = 0;
    uint64_t exp = 1;
    while(number)
    {
	int digit = number % 10;
	number /= 10;

	sum += digit * exp;
	exp *= 2;
    }

    printf("%" PRIu64 "\n", sum);
}    


/*
* Задача 2
* ----
* Да се напише програма, която по въведени от клавиатурата неотрицателно цяло число 
* x и цифра y намира поредния номер на първото срещане на y в x.
*/ 

void t2()
{
    int32_t num;
    int32_t search;

    printf("Insert number: ");
    int32_t check1 = scanf("%" SCNd32, &num);

    printf("Insert number to find: ");
    int32_t check2 = scanf("%" SCNd32, &search); 
    
    if(check1 != 1 && check2 != 1)
    {
	fprintf(stderr, "Invalid input!");
	exit(-1);
    }

    int32_t index = 1;
    while(num)
    {
	int32_t digit = num % 10;

	if(digit == search)
	{
	    printf("Found number at index: %" PRId32, index);
	    exit(0);
	}

	num /= 10;
	index++;
    }

    puts("Digit not found!");
    exit(1);
}    

/*
*  Задача 3
*  ---
*  Реализирайте програма, която по подадено от конзолата число n намира
*  n-тото число на Фибоначи.
*/
void t3()
{
    int32_t f1 = 1;
    int32_t f2 = 1;

    int32_t fib_number;
    printf("Insert n: ");

    int32_t res = scanf("%" SCNd32, &fib_number);
    if(res != 1)
    {
	fprintf(stderr, "Invalid number!");
	exit(1);
    }

    int32_t num = 0;
    for(int32_t i = 3; i <= fib_number; ++i)
    {
	num = f1 + f2;
	
	f2 = f1;
	f1 = num;
    }

    printf("The number is: %" PRId32 "\n", num);
}


/*
*  Задача 4
*  ---
*  Напишете програма, която по подадено число n връща резултат дали n е просто число или не.
*/ 
void t4()
{
    int32_t number;
    printf("Insert number to check: ");

    int32_t args = scanf("%" SCNd32, &number);
    if(args != 1)
    {
	fprintf(stderr, "Invalid number!");
	exit(1);
    }

    int32_t sqr_n = (int)sqrt((double)number);
    for(int32_t i = 2; i <= sqr_n; ++i)
    {
	if(number % i == 0)
	{
	    puts("The number is not prime!");
	    exit(1);
	}
    }

    if(number == 1) puts("The number is not prime!");
    else            puts("The number is prime!");
}    


/*
*  Задача 5
*  ----
*  Реализирайте алгоритъма на Евклид за намиране на НОД (най-голям общ делител).
*/
void t5()
{
    int32_t num1, num2;
    printf("Insert numbers: ");

    int32_t check = scanf("%" SCNd32 "%" SCNd32, &num1, &num2);
    if(check != 2)
    {
	fprintf(stderr, "Invalid input!");
	exit(1);
    }

    // Искаме а да е по-голямо от b 
    int32_t a = num1 > num2 ? num1 : num2;
    int32_t b = a == num1 ? num2 : num1;

    if(b == 0)
    {
	fprintf(stderr, "Zero found!");
	exit(1);
    }

    while(b != 0)
    {
	int tmp = a % b;

	a = b;
	b = tmp;
    }

    printf("GDC is: %" PRId32, a);
}    

/*
*  Задача 6
*  ----
*  Реализирайте програма, която представя естествено число n като произведение от неговите прости множители.
*/
void t6()
{
    int32_t number;
    printf("Insert number: ");

    int32_t check = scanf("%" SCNd32, &number);
    if(check != 1)
    {
	fprintf(stderr, "Invalid input!");
	exit(1);
    }

    for(int32_t i = 2; i <= number; ++i)
    {
	// Докато числото се дели,
	// така никога няма да има съставно число в представянето
	while(number % i == 0)
	{
	    printf("%" PRId32 " " , i);
	    number /= i;
	}
    }
}    


/*
*  Задача 7
*  ----
*  Напишете програма, която приема цяло число и връща броя на единиците в двоичния му запис.
*/
void t7()
{
    uint32_t number;

    printf("Insert number to check: ");
    uint32_t check = scanf("%" SCNu32, &number);

    if(check != 1)
    {
	fprintf(stderr, "Invalid input!");
	exit(1);
    }

    int32_t cnt = 0;
    for(int32_t i = 0; i < sizeof(int32_t) * 8; ++i)
    {
	cnt += (number & (1 << i)) != 0;
    }

    printf("%" PRId32, cnt);
}    


/*
*  Задача 8
*  ----
*  Напишете функция, която проверява дали двоичният запис на едно цяло
*  число е палиндром (чете се еднакво отляво надясно и отдясно наляво).
*  Не разглеждаме водещи нули.
*/

void t8()
{
    uint32_t number;

    printf("Insert number: ");
    int32_t check = scanf("%" SCNu32, &number);
    if(check != 1)
    {
	fprintf(stderr, "Invalid input!");
	exit(1);
    }

    // Вземаме най-значимата единица 
    int32_t max_bit = floor(log2(number));


    for(int32_t i = 0; i <= max_bit; ++i)
    {
	// Обхождаме от края и от началото
	int32_t b1 = (number & (1 << i)) != 0;
	int32_t b2 = (number & (1 << max_bit - i)) != 0;
	
	if(b1 != b2)
	{
	    puts("Not a palindrome!");
	    exit(0);
	}
    }

    puts("Palindrome!");
    exit(0);
}    

/*
*  Задача 9
*  ----
*  Напишете програма, която прочита 2 цели числа от конзолата,
*  намира техния сбор и разлика и ги принтира на конзолата.
*/

void t9()
{
    int32_t number1, number2;

    printf("Insert number: ");
    int32_t check = scanf("%" SCNd32 "%" SCNd32, &number1, &number2);
    if(check != 2)
    {
	fprintf(stderr, "Invalid input!");
	exit(1);
    }
    
    int32_t sum   = 0;
    int32_t carry = 0;

    uint32_t res = 0;
    for(int32_t i = 0; i < sizeof(int32_t) * 8; ++i)
    {
	int32_t d1 = (number1 & (1 << i)) != 0;
	int32_t d2 = (number2 & (1 << i)) != 0;

	/*
	*  a b     carry   
	*  1 1 | 0      1 | 1
	*  0 0 | 0      1 | 1
	*  1 0 | 1      1 | 0
	*  0 1 | 1      1 | 0
	*/
	
	sum = d1 ^ d2 ^ carry;
	carry = (d1 & d2) | (d1 & carry) | (d2 & carry);

	res = res | (sum << i);
    }

    printf("The sum is: %" PRId32, res);
}    

