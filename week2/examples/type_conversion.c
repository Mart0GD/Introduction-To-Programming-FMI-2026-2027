#include <stdio.h>

int main(){

    float real = 2.334;
    
    // Имплицитно преобразуване със загуба
    int result_with_loss = real;                // 2

    // Имплицитно преобразуване без загуба
    double result_without_loss = real;          // 2.334

    // Експлицитно преобразуване
    int     cast_with_loss      = (int)real;    // 2
    double  cast_without_loss   = (double)real; // 2.334

    /*  Преобразуване на типове в изрази
           char / short
                ↓
               int
                ↓
            unsigned int
                ↓
              long
                ↓
           unsigned long
                ↓
            long long
                ↓
        unsigned long long
                ↓
              float
                ↓
              double
                ↓
           long double

           !! Важно !!
    */
    return 0;
}