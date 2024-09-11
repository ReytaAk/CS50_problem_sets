#include <cs50.h>
#include <stdio.h>

bool checksum (long cc);
void print_card_brand( long cc);
int main(void)
{
    long cc = get_long("Number: ");

    if (checksum(cc))
        print_card_brand(cc);
    else
        printf("INVALID\n");
}

bool checksum (long cc)
{
    int sum = 0;
    int ld;
    while (cc > 0)
    {
        ld = cc % 10;
        sum = sum + ld;
        cc = cc - ld;
        cc = cc / 10;
        ld = cc % 10;
        cc = cc - ld;
        cc = cc / 10;
        ld = ld * 2;
        if (ld >= 10)
        {
            int x = ld % 10;
            ld = ld - x;
            ld = ld / 10;
            int y = ld % 10;
            ld = x + y;
        }
        sum = sum + ld;
    }
    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void print_card_brand(long cc)
{
    if ((cc > 3999999999999 && cc < 5000000000000) || (cc > 3999999999999999 && cc < 5000000000000000))
    {
        printf("VISA\n");
    }
    else if ((cc > 339999999999999 && cc < 350000000000000) || (cc > 369999999999999 && cc < 380000000000000))
    {
        printf("AMEX\n");
    }
    else if ((cc > 5099999999999999 && cc < 5600000000000000))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}