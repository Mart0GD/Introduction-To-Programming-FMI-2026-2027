#include <stdio.h>

int main(){

    int number_one = 1;
    int number_two = 2;

    printf("Printing all Arithmetic operators: \n");

    // ------------------ БИНАРНИ ОПЕРАЦИИ ------------------
    printf("%d + %d = %d\n", number_one, number_two, number_one + number_two);    // Събиране
    printf("%d - %d = %d\n", number_one, number_two, number_one - number_two);    // Изваждане 
    printf("%d * %d = %d\n", number_one, number_two, number_one * number_two);    // Умножение
    printf("%d / %d = %d\n", number_one, number_two, number_one / number_two);    // Деление
    printf("%d %% %d = %d\n", number_one, number_two, number_one % number_two);   // Взимане по модул

    // ------------------ УНАРНИ ОПЕРАЦИИ ------------------
    printf("+ number_one:   %d\n", +number_one);    // Унарен плюс
    printf("- number_one:  %d\n", -number_one);     // Унарен минус

    printf("++ number_one:  %d\n", ++number_one);   // Префиксно увеличаване
    printf("++ number_two:  %d\n", ++number_two);   // Префиксно увеличаване

    printf("-- number_one:  %d\n", --number_one);   // Префиксно намаляване
    printf("-- number_two:  %d\n", --number_two);   // Префиксно намаляване

    printf("number_one ++:  %d\n", number_one++);   // Постфиксно увеличаване
    printf("number_two ++:  %d\n", number_two++);   // Постфиксно увеличаване

    printf("number_one on the next line: %d\n", number_one);
    printf("number_two on the next line: %d\n", number_two);

    printf("number_one --:  %d\n", number_one--);   // Постфиксно намаляване
    printf("number_two --:  %d\n", number_two--);   // Постфиксно намаляване

    printf("number_one on the next line: %d\n", number_one);
    printf("number_two on the next line: %d\n", number_two);

    printf("Final result:\n");
    printf("Number one:     %d\n", number_one);
    printf("Number two:     %d\n", number_two);

   
    
   return 0;
}