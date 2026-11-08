#include <stdio.h>

int  do_smth(int a, int b);
int  do_smth_correct(int a, int b);
void void_return_example(int a);

int main(void) { 

    int some_value;

    some_value = do_smth(1, 2);          // !!НЕДЕФИНИРАНО ПОВЕДЕНИЕ!!
                                         // 1 > 2 е лъжа, функцията стига до края без return,
                                         // а ние ИЗПОЛЗВАМЕ върнатата "стойност".
                                         // В some_value може да има каквото и да е.

    some_value = do_smth_correct(1, 2);  // OK: some_value = 6

    void_return_example(6);              // извежда: number is >= 5

    return 0;  // Всяка функция с тип на връщане (различен от void) ТРЯБВА да върне стойност.
               // (main е единственото изключение: без return се приема return 0;)
}

void void_return_example(int a) {

    /*
        При void функции 'return;' (без стойност) просто прекратява функцията
        по-рано. Това е позволено и често се използва като "ранен изход".
    */

    if (a < 5) return;   // при a < 5 функцията спира тук и нищо не се извежда

    printf("number is >= 5\n");
}   // тук void функцията приключва сама, return не е нужен

int do_smth(int a, int b) {

    /*
        ГРЕШНА функция!
        Ако функцията има тип на връщане, всеки възможен път (клон)
        в нея трябва да завършва с return и стойност.

        Тук при a <= b няма return. Функцията "пада" от края си,
        без да върне нищо.
    */

    if (a > b) return 5;

    // липсва return за случая a <= b
}

int do_smth_correct(int a, int b) {

    /*
        ПРАВИЛНА функция.
        Всеки възможен път завършва с return.
    */

    if (a > b) return 5;  // функцията спира изпълнението си тук

    return 6;             // стойност по подразбиране (когато a <= b)
}
