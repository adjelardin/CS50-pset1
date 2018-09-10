#include <stdio.h>
#include <cs50.h>

int main()
{
    // get user's credit card number
    long long num = get_long_long("Enter your credit card number: ");

    // store each digit of the number
    int digits[16];
    for (int i = 0; i < 16; i++)
    {
        if (num <= 0) // last digit reached
        {
            digits[i] = -1;
        }
        else
        {
            digits[i] = num % 10;
            num /= 10;
        }
    }

    // Get card type
    string card;
    if ((digits[13] == -1 && digits[12] == 4) || digits[15] == 4)
    {
        card = "VISA";
    }
    else if (digits[15] == -1 && digits[14] == 3 && (digits[13] == 4 || digits[13] == 7))
    {
        card = "AMEX";
    }
    else if (digits[15] == 5 && digits[14] >= 1 && digits[14] <= 5)
    {
        card = "MASTERCARD";
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }

    // Luhn's algorithm
    for (int i = 1; digits[i] != -1 && i < 16; i += 2)
    {
        digits[i] *= 2;
        if (digits[i] >= 10)
        {
            digits[i] = digits[i] % 10 + digits[i] / 10 % 10;
        }
    }
    int sum = 0;
    for (int i = 0; digits[i] != -1 && i < 16; i++)
    {
        sum += digits[i];
    }

    // checksum
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    printf("%s\n", card);
    return 0;
}
