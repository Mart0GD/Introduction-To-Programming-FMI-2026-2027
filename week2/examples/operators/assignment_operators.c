#include <stdio.h>

int main()
{
    /*
    *   LValue -> всяка променлива, която има строго място в паметта. 
    *   number1 и number2 са такива, тъй като можем да се обърнем към тях
    */

    int number_one = 1; // -> LValue
    int number_two = 2; // -> LValue

    printf("number_one += number_two = %d", number_one += number_two);
    printf("number_one -= number_two = %d", number_one -= number_two);
    printf("number_one *= number_two = %d", number_one *= number_two);
    printf("number_one /= number_two = %d", number_one /= number_two);
    printf("number_one %%= number_two = %d", number_one %= number_two);

    
    /*
    *   RValue -> това е всичко, което не е LValue     
    *
    *   Оператор = очаква LValue в ляво и RValue в дясно и връща RValue
    *   Оператор ++ (Постиксен) връща RValue
    * 
    *   Затова следните са невъзможни:
    * 
    *   ++number_one++ --> ++(number_one++) --> ++(RValue) --> ГРЕШКА 
    *   (number_one = number_two) = 2 --> (RValue) = 2 --> RValue = RValue --> ГРЕШКА 
    */
   
    number_one = number_two = 2; // -> RValue

    printf("number_one = %d", number_one);
    printf("number_two = %d", number_two);

    return 0;
}