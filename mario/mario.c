#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get height from the user
    int h = 0;
    do
    {
        h = get_int("Please input a positive height less than 24: ");
    }while (h < 1 || h > 23);
    
    // iteratively create pyramid
    for (int i = 1; i <= h; i++)
    {
        for (int j = i; j < h; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  "); // Space between pyramid (2 spaces)
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n"); // Newline after each row
    }
}
