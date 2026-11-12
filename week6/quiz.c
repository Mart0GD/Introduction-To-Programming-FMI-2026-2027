

int main(void)
{

    // -- Какво ще се отпечата? --
    
    for (int i = 0; i < 6; i++) {
        if (i == 2) continue;
        if (i == 4) break;
        
        printf("%d ", i);
    }

    // -- Колко звезди ще се отпечатат? --

    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            printf("*");
        }
    }

    // -- Колко са i,j накрая? --

    int i, j, count = 0;
    for (i = 0, j = 10; i < j; i += 2, j -= 2)
    {
        count++;
    }
    printf("%d %d %d\n", count, i, j);

    // -- Какво става тук? --
    
    int i;
    for (i = 0; i = 5; i++)
    {
        printf("%d ", i);
    }

    // -- ?? --

    unsigned int i;
    for (i = 10; i >= 0; i--)
    {
        printf("%u ", i);    
    }

    
    return 0;
}    
