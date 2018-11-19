#include <stdio.h>

int partition(int A[], int m, int n)
{
    int x = A[m];
    int i = m;
    int j,temp;
    for(j = m + 1; j <= n; j++)
    {
        if(A[j] <= x)
        {
            i=i+1;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i];
    A[i] = A[m];
    A[m] = temp;
    return i;
}

void quicksort(int A[], int m, int n)
{
    int q;
    if(m < n)
    {
        q = partition(A, m, n);
        quicksort(A, m, q-1);
        quicksort(A, q+1, n);
    }
}

int main()
{
    int A[10] = {20, 54, 5, 56, 0, -78, 64, 6, 8, 6};
    int i;

    printf("排序前：");
    for(i = 0; i < 10; i++)
    {
        printf("%5d", A[i]);
    }
    printf("\n");

    quicksort(A, 0, 9);

    printf("排序后：");
    for(i = 0; i < 10; i++)
    {
        printf("%5d", A[i]);
    }
    printf("\n");

    return 0;
}