#include <stdio.h>

int main(){

    int number_one = 1;
    int number_two = 2;

    // Бинарни
    printf("number_one && number_two = %d\n", number_one && number_two);
    printf("number_one || number_two = %d\n", number_one || number_two);

    // Унарни
    printf("!number_one = %d\n", !number_one);
    printf("!number_two = %d\n", !number_two);

    /*
    *   Оператор "," е малко по-специален!
    *
    *   (<expression>, <expression>, ...) --> n израза
    *   Стойността на оператора е стойността на последния израз
    */
    printf("1+2 = %d\n", (0 + 1, 16 + 12, 1 + 2));

    return 0;
}