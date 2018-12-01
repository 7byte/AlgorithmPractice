#include<stdio.h>

// 自顶向下
int fiboFromTop(int n)
{
    if(n == 1 || n == 2) return 1;
    return fiboFromTop(n-1)+fiboFromTop(n-2);
}

// 自底向上
int fiboFromBottom(int n)
{
    int a = 1, b = 1, x;

    if(n == 1 || n == 2) return 1;

    while(n > 2)
    {
        x = b;
        b = a+b;
        a = x;
        n--;
    }
    return b;
}

// {{a, b}, {c, d}}
typedef struct matrix_2_2
{
    int a, b, c, d;
}matrix;

matrix A = {1, 1, 1, 0};

void multiply(matrix x, matrix y, matrix *result)
{
    result->a = x.a * y.a + x.b * y.c;
    result->b = x.a * y.b + x.b * y.d;
    result->c = x.c * y.a + x.d * y.c;
    result->d = x.c * y.b + x.d * y.d;
}

void power(int n, matrix *result)
{
    matrix p;
    if(n == 1)
    {
        result->a = A.a;
        result->b = A.b;
        result->c = A.c;
        result->d = A.d;
        return;
    }
    if((n&1) == 0)
    {
        power(n/2, &p);
        multiply(p, p, result);
        return;
    }
    power((n-1)/2, &p);
    multiply(p, p, result);
    multiply(*result, A, result);
    return;
}

// 矩阵乘方
int fiboMatrix(int n)
{
    matrix m;
    power(n, &m);
    return m.b;
}

int main()
{
    int i, count = 20;

    for (i = 1; i <= count; i++) printf("%d  ", fiboFromTop(i));
    printf("\n");

    for (i = 1; i <= count; i++) printf("%d  ", fiboFromBottom(i));
    printf("\n");

    for (i = 1; i <= count; i++) printf("%d  ", fiboMatrix(i));
    printf("\n");
    
    return 0;
}
