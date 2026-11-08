#include <stdio.h>
        
/*        
 *  Прототипи (декларации) на функциите.
 *  Компилаторът чете файла отгоре надолу. Без тези редове той няма да знае
 *  какво е function_one, когато я срещне в main, защото дефиницията ѝ е по-долу.
 */
void function_one(void);
void function_two(void);
void function_three(void);

int main(void) {

    /*
    *    Функциите се изпълняват според следния принцип - "Последният влязъл е първият излязъл".
    *
    *    Важо е да се знае, че за всяка функция се заделя парче памет, наречено "рамка".
    *
    *    В него се съдържа:
    *     
    *    1) Променливите.
    *    2) Информация за дебъгване.
    *    3) Адрес за връщане след изпълнение на функцията.
    */    

    
    /*
    *    Примерен ход на една програма:
    *
    *    1) Стартира се функцията "main". Тя е началото на програмата.
    *       Операционната система създава за нея рамка (stack frame) в стека.
    *
    *    2) main извиква друга функция. Изпълнението на main спира
    *       на този ред и се запомня адресът, към който да се върнем.
    *
    *    3) За новата функция "foo" се създава рамка върху стека
    *       и тя започва да се изпълнява веднага.
    *
    *       3.1) Ако foo извика "foo2", foo спира, върху стека се слага
    *            рамка за foo2 и тя се изпълнява. И така нататък...
    *
    *    4) Когато "foo" приключи, рамката ѝ се маха от стека,
    *       евентуално се връща резултат и контролът се подава
    *       обратно на "main", точно на реда след извикването.
    *
    *    5) main приключва с return 0. Ресурсите на програмата се освобождават,
    *       а операционната система получава код 0 ("успешно завършване").
    */

    function_one();   // main спира тук и чака function_one да завърши

    return 0; // край на програмата (изпълнява се чак след като function_one се върне)
}

void function_one(void) {

    /*
        main е на пауза, докато function_one се изпълнява.
        Стек: [main] -> [function_one]
    */

    puts("inside function one!");
    function_two();   // function_one спира тук

    // някакви операции... (изпълняват се чак след като function_two се върне)
}

void function_two(void) {

    /*
        function_one е на пауза, докато function_two се изпълнява.
        Стек: [main] -> [function_one] -> [function_two]
    */

    puts("inside function two!");
    function_three(); // function_two спира тук

    // Продължаваме оттук, след като function_three приключи:
    puts("calculating the meaning of life....");
    puts("calculating the meaning of life....");
    puts("calculating the meaning of life....");
    puts("calculating the meaning of life....");

    puts("The meaning of life is: 42");
}   // function_two приключва и контролът се връща на function_one

void function_three(void) {

    /*
        function_two е на пауза, докато function_three се изпълнява.
        Стек: [main] -> [function_one] -> [function_two] -> [function_three]
        Това е най-дълбоката точка на програмата.
    */

    puts("inside function three!");
}   // function_three приключва първа (тя е влязла последна)
