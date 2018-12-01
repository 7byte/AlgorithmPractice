#include<stdio.h>

int power(int x, unsigned n)
{
    int p;
    if(n == 0) return 1;
    if(n == 1) return x;
    if((n&1) == 0)
    {
        p = power(x, n/2);
        return p*p;
    }
    p = power(x, (n-1)/2);
    return p*p*x;
}

float powx(int x, int n)
{
    if(n < 0)
    {
        return 1.0/power(x, -n);
    }
    return power(x, n);
}

int main()
{
    printf("powx(5, -1) expect 0.2, got %f\n", powx(5, -1));
    printf("powx(5, -4) expect 0.0016, got %f\n", powx(5, -4));
    printf("powx(5, -5) expect 0.00032, got %f\n", powx(5, -5));
    printf("powx(5, 0) expect 1, got %f\n", powx(5, 0));
    printf("powx(5, 4) expect 625, got %f\n", powx(5, 4));
    printf("powx(5, 5) expect 3125, got %f\n", powx(5, 5));
    return 0;
}
