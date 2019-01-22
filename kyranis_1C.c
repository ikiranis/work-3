/**
 *
 * File: kyranis_1C.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 23/1/2019
 * Time: 12:46 πμ
 *
 */

#include <stdio.h>

int f(int n);

int main()
{
    printf("%d\n", f(23));

    return 0;
}

int f(int n)
{
    if (n<=1)
        return 1;

    if (n%5==0)
        return f(n/5)+5;
    else
        if (n%4==2)
            return f(n/2)+2;
        else
            return f((n-1)/2)+3;
}