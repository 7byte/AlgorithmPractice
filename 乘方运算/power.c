#include<stdio.h>
#include<time.h>

typedef int (*Power)(int, unsigned);

int power_recursive(int x, unsigned n)
{
    int p;
    if(n == 0) return 1;
    if(n == 1) return x;
    if((n&1) == 0)
    {
        p = power_recursive(x, n/2);
        return p*p;
    }
    p = power_recursive(x, (n-1)/2);
    return p*p*x;
}

int power_not_recursive(int x, unsigned n)
{
    int k = 1;
    if(n == 0) return 1;
    while (n > 1)
    {
        if ((n&1) == 1) k *= x;
        x *= x;
        n >>= 1;
    }
    return k * x;
}

double powx(int x, int n, Power power)
{
    if(n < 0)
    {
        return 1.0/power(x, -n);
    }
    return power(x, n);
}

typedef struct testcase
{
    int x;
    int n;
    double expect;
}testcase;

testcase cases[] = 
{
    {5, -13, 0.0000000008192},
    {5, -5, 0.00032},
    {5, -1, 0.2},
    {5, 0, 1},
    {5, 1, 5},
    {5, 5, 3125},
    {5, 13, 1220703125}
};

void test(Power power)
{
    int i = 0;
    clock_t t1 = clock();
    for(i; i < sizeof(cases)/sizeof(testcase); i++)
    {
        testcase c = cases[i];
        printf("powx(%d, %d) expect %g, got %g\n", c.x, c.n, c.expect, powx(c.x, c.n, power));
    }
    clock_t t2 = clock();
    printf("cost time: %fs\n\n", difftime(t2, t1)/CLOCKS_PER_SEC);
}

int main()
{
    test(power_recursive);
    test(power_not_recursive);
    return 0;
}
