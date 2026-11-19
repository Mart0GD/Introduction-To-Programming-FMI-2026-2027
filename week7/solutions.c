#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define SIZE 128
#define HISTOGRAM_SIZE 256

void read_array(int arr[], int n);
void print_array(const int arr[], int n);

void t2(void);
void t3(void);
void t4(void);
void t5(void);
void t6(void);
void t9(void);
void t10(void);
void t13(void);
void t14(void);

// Custom bool
typedef char _bool;

#define true  1
#define false 0


int main(void)
{
    t14();
    return 0;
}

/*
*    Задача 2
*    ------
*    Напишете програма, която прочита от конзолата число n (n <= 128) и след това прочита и n на брой елементи.
*    Съберете всички съседни елементи от ляво надясно (последният елемент запазва стойността си) и принтирайте резултата!
*/

void read_array(int arr[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        // алтернативно
        // scanf("%d", (arr + i));
        int res = scanf("%d", &arr[i]);

        if(res != 1)
        {
            puts("Invalid input!");
            exit(1);
        }        
    }
}    

void print_array(const int arr[], int size)
{
    putchar('[');
    for(int i = 0; i < size; ++i)
    {
        printf("%d", arr[i]);
        if(i + 1 != size) printf(", ");
    }
    putchar(']');
}    

void t2(void)
{
    int arr[SIZE];
    int n;

    int res = scanf("%d", &n);
    if(res != 1 || n > SIZE)
    {
        puts("Invalid input!");
        exit(1);
    }

    read_array(arr, n);

    for(int i = 0; i < n - 1; ++i)
    {
        arr[i] = arr[i] + arr[i + 1];
    }

    print_array(arr,n);
}    

/*
*    Задача 3
*    -------
*    Напишете функция transform, която получава аргумент масив и преобразува всички негови елементи по следната схема:

*    По-малките от 0 се заменят с квадрата си.
*    По-големите от 0 с половината си.
*    Всяка нулата се заменя с единица.
*/

void t3(void)
{
    int arr[SIZE];
    int n;

    int res = scanf("%d", &n);
    if(res != 1 || n > SIZE)
    {
        puts("Invalid input!");
        exit(1);
    }

    read_array(arr,n);

    for(int i = 0; i < n; ++i)
    {
        if(arr[i] < 0)
        {
            arr[i] = arr[i] * arr[i];
        }
        else if(arr[i] > 0)
        {
            arr[i] = arr[i] / 2;
        }
        else
        {
            arr[i] = 1;
        }
    }

    print_array(arr,n);
}    


/*
*    Задача 4
*    -------
*    Напишете функция checkNext, която проверява дали в масив от числа
*    има два последователни равни елементи.
*/

_bool check_next(int arr[], int size)
{    
    for(int i = 0; i < size - 1; ++i)
    {
        if(arr[i] == arr[i + 1])
        {
            return true;
        }
    }

    return false;
}        

void t4(void)
{
    int arr[SIZE];
    int n;

    int check = scanf("%d", &n);
    if(check != 1 || n > SIZE)
    {
            puts("Invalid input");
        exit(1);
    }

    read_array(arr,n);

    _bool res = check_next(arr, n);

    res  && puts("There are equal elements!");
    !res && puts("There are no equal elements!");
}    


/*
*    Задача 5
*    -------
*    Напишете функция removePrime, която премахва всяко просто число от масив с положителни елемнти.
*/

_bool is_prime(int number)
{
    if(number == 1) return false;
    
    int sq = sqrt((double)number);
    for(int i = 2; i <= sq; ++i)
    {
        if(number % i == 0)
        {
            return false;
        }
    }

    return true;
}    

void remove_element(int arr[], int index, int* size)
{
    /*
    *    Assert е инструмент, който подсигурява,
    *    че ще спрем програмата ако условието не е изпълнено!
    *
    *    Намира се в header-a <assert>
    */
    assert(index >= 0 && index < *size);
    
    // Идея - преместваме елементите с едно наляво,
    // започвайки от индекса, който е подаден!

    for(int i = index; i < *size - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }

    // смъкваме размера 
    (*size) = (*size) - 1;
}    

void t5(void)
{
    int arr[SIZE];
    int n;

    int check = scanf("%d", &n);
    if(check != 1 || n > SIZE)
    {
        puts("Invalid input!");
        exit(1);
    }

    read_array(arr,n);

    for(int i = 0; i < n; ++i)
    {
        if(is_prime(arr[i]))
        {
            remove_element(arr,i,&n);
            i--; // индекса се промени, връщаме назад!
        }
    }

    print_array(arr,n);
}    

/*
*    Задача 6
*    -------
*
*    Напишете Функция histogram, която получава като аргумент масив с елементи числа със стойности между 0 и 255
*    и намира броя срещания на всеки от тях.
*
*    Нека тук максималната големина на масива е 512.
*/

void t6(void)
{
    const int A_SIZE   = 512;

    int arr[A_SIZE];
    
    // Зануляваме стойностите!
    // Работи само за големина compile time константа
    int histogram[HISTOGRAM_SIZE] = {0}; 

    // Алтернатива
    // int histogram[HISTOGRAM_SIZE] = {[0 ... HISTOGRAM_SIZE - 1] = 0};

    int n;
    int check = scanf("%d", &n);
    if(check != 1 || n > A_SIZE)
    {
        puts("Invalid input!");
        exit(1);
    }
    
    read_array(arr, n);

    for(int i = 0; i < n; ++i)
    {
        if(arr[i] >= HISTOGRAM_SIZE || arr[i] < 0)
        {
            puts("Invalid array data. Values must be in [0,255]!");
            exit(1);
        }

        histogram[arr[i]]++;
    }
    
    for(int i = 0; i < HISTOGRAM_SIZE; ++i)
    {
        printf("%d ---> %d\n", i, histogram[i]);
    }
}    

/*
*    За масив от цели числа, да се провери дали е битонично подреден. Това означава, дали е съставен от два подмасива,
*    за които след размяна на местата им се получава сортиран масив. Единият може да е празен.
*
*    Изведете дали масивът е битично подреден.
*/

_bool is_bitonic(const int arr[], int n)
{
    // Има само едно място където стойността може да пада
    // {5,1,2,3}     -> между 5 и 1
    // {1,2,3,-1,-2} -> между 3 и -1
    // {1,3,2}       -> пада между 3 и 2 както и между 2 и 1 (не става)
    // {1,2,3,4,5}   -> няма падане (сортиран е)
    
    int drops = 0;
    
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] > arr[(i + 1) % n])
        {
            drops++;
        }

        if(drops> 1) return false;
    }

    return true;
}

void t9(void)
{
    int arr[SIZE];
    int n;

    int check = scanf("%d", &n);
    if(check != 1 || n > SIZE)
    {
        puts("Invalid input!");
        exit(1);
    }

    read_array(arr,n);

    printf("Is bitonic: %s", is_bitonic(arr,n) ? "yes" : "no");
}    

/*
*    Задача 10
*    ------
*    Две числови редици си приличат, ако съвпадат множествата от числата, които ги съставят.
*    Да се напише програма, която установява дали числовите редици a0, a1, ..., an-1 и b0, b1, ..., bn-1 си приличат.
*/

_bool contains(const int arr[], int elem, int size)
{
    for(int i = 0; i < size; ++i)
    {
        if(arr[i] == elem) return true;
    }

    return false;
}

_bool subset(const int set1[], int set1_size, const int set2[], int set2_size)
{
    for(int i = 0; i < set1_size; ++i)
    {
        if(!contains(set2, set1[i], set2_size)) return false;
    }

    return true;
}

void t10(void)
{
    int arr_a[SIZE];
    int arr_b[SIZE];

    int n;
    int check = scanf("%d", &n);
    if(check != 1 || n > SIZE)
    {
        puts("Invalid input!");
        exit(1);
    }

    read_array(arr_a, n);
    read_array(arr_b, n);

    _bool res = subset(arr_a, n, arr_b, n) && subset(arr_b, n, arr_a, n);

    res && puts("Same set!");
    !res && puts("Not the same set!");
}

/*
*    Задача 13
*    --------
*    Приема се масив, в който всяко число се среща два пъти, с изключение на едно число, което се среща точно веднъж.
*    Напишете функция, която връща кое е това число.
*
*    Използвайте побитови операции, за да постигнете решение без вложени цикли (линейно решение)
*/

void t13(void)
{
    int arr[SIZE];
    int n;

    int res = scanf("%d", &n);
    if(res != 1 || n > SIZE)
    {
        puts("Invalid input!");
        exit(1);
    }

    read_array(arr,n);

    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        sum ^= arr[i];
    }

    printf("The unique element is: %d", sum);
}    

/*
*    Задача 14
*    --------
*    Напишете програма, която да принтира на конзолата първите 128 прости числа.
*/
void t14(void)
{
    int numbers[SIZE + 1] = {0};
    
    numbers[0] = 1; // 0 не е просто
    numbers[1] = 1; // 1 не е просто

    for(int i = 2; i < SIZE; ++i)
    {
        if(numbers[i]) continue;

        for(int j = i + i; j <= SIZE; j+=i)
        {
            numbers[j] = 1;
        }
    }

    for(int i = 0; i < SIZE; ++i)
    {
        if(numbers[i] == 0)
        {
            printf("%d ", i);
        }
    }
}
