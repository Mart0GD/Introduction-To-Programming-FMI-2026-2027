#include <stdio.h>

int main(){

    int number_one = 1;
    int number_two = 2;

    printf("number_one < number_two  = %d", number_one < number_two);   // по-малко 
    printf("number_one <= number_two = %d", number_one <= number_two);  // по-малко или равно

    printf("number_one > number_two  = %d", number_one > number_two);   // по-голямо
    printf("number_one >= number_two = %d", number_one >= number_two);  // по-голямо или равно

    printf("number_one == number_two = %d", number_one == number_two);  // равни
    printf("number_one != number_two = %d", number_one != number_two);  // различни 
    
    return 0;
}