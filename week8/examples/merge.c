#include <stdio.h>

#define SIZE1 5
#define SIZE2 7

int main(void)
{    
    int arr1[SIZE1] = {1, 3, 5 , 7 , 9};
    int arr2[SIZE2] = {2, 3, 4 , 4 , 10, 104 , 273};

    int merged[SIZE1+SIZE2];
    
    int i1=0, i2=0, im=0;
    while(i1 < SIZE1 && i2 < SIZE2)
    {
        if(arr1[i1] < arr2[i2])
        {
            merged[im] = arr1[i1++];
        }
        else
        {
            merged[im] = arr2[i2++];
        }

        im++;
    }

    // Допълваме с останлото от единия или другия (ако има)
    while(i1 < SIZE1) merged[im++] = arr1[i1++];
    while(i2 < SIZE2) merged[im++] = arr2[i2++];

    for(int i = 0; i < SIZE1+SIZE2; ++i)
    {
        printf("%d ", merged[i]);
    }
    
    return 0;
}
