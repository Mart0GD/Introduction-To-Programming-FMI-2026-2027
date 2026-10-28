#include <stdio.h>

// Какво очаквате да стане в кода
int main(){

    // =========== Въпрос 1 ===========
    int x = 6;

    if(x >= 0)
        if(x <= 5) printf("x is in in [0,5]\n");
    else 
        printf("x is negative!\n");

    // =========== Въпрос 2 ===========
    x = -6;

    if(x >= 0)
        if(x <= 5) printf("x is in in [0,5]\n");
    else 
        printf("x is negative!\n");
    
    // =========== Въпрос 3 ===========

     x = 6;

    if(x >= 0)
    {
        if(x <= 5) printf("x is in in [0,5]\n");
    }
    else 
        printf("x is negative!\n");

	
    // =========== Въпрос 4 ===========

    int expr = 10;
    int sum  = 0;
    
    switch(expr)
    {
	case 10: sum++;
	case 8 : sum++;
	case 6 : sum++;
	case 2 : sum++;
	
	default: break;
    }

    printf("%d", sum);

    
    // =========== Въпрос 5 ===========

    unsigned days = 0;
    unsigned month = 2;

    switch (month)
    {
        default: days += 1;
        case 4:
        case 6:
        case 9:
        case 11: days += 2;
        case 2: days += 28;
    }

    printf("Дните във февруари: %d", days);

    // =========== Въпрос 6 ===========

    int  num1;
    char symb;

    scanf("%d", &num1);
    scanf("%c", &symb);

    return 0;
}
