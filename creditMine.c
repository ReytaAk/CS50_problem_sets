#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cc = get_long("Number: ");

    long ccx = cc;
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
        if ((ccx > 3999999999999 && ccx < 5000000000000) || (ccx > 3999999999999999 && ccx < 5000000000000000))
        {
            printf("VISA\n");
        }
        else if ((ccx > 339999999999999 && ccx < 350000000000000) || (ccx > 369999999999999 && ccx < 380000000000000))
        {
            printf("AMEX\n");
        }
        else if ((ccx > 5099999999999999 && ccx < 5600000000000000))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
