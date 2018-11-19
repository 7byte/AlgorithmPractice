#include <stdio.h>

void walk(int row, int col, int a[row][col])
{
    int count = col*row, x = col, y = row;
    int i = 0, j = 0, k;
    
    while(count>0)
    {
        if (x == 1)
        {
            printf("%d ", a[i][j++]);
            count--;
        }
        else
        {
            for(k = 1; k < x; k++)
            {
                printf("%d ", a[i][j++]);
                count--;
            }
        }
        if (count <= 0)
        {
            break;
        }
        
        if (y == 1)
        {
            printf("%d ", a[i++][j]);
            count--;
        }
        else
        {
            for(k = 1; k < y; k++)
            {
                printf("%d ", a[i++][j]);
                count--;
            }
        }
        if (count <= 0)
        {
            break;
        }
        
        for(k = 1; k < x; k++)
        {
            printf("%d ", a[i][j--]);
            count--;
        }
        
        for(k = 1; k < y; k++)
        {
            printf("%d ", a[i--][j]);
            count--;
        }

        i++;
        j++;
        x-=2;
        y-=2;
    }
    printf("\n");
}

int case1[1][1] = {{1}};

int case2[1][4] = {{1, 2, 3, 4}};

int case3[4][1] = {{1},{2},{3},{4}};

int case4[3][3] = {{1, 2, 3},{8, 9, 4},{7, 6, 5}};

int case5[4][4] = {{1, 2, 3, 4},{12, 13, 14, 5},{11, 16, 15, 6},{10, 9, 8, 7}};

int case6[2][4] = {{1, 2, 3, 4},{8, 7, 6, 5}};

int case7[4][2] = {{1, 2},{8, 3},{7, 4},{6, 5}};

int main()
{
    walk(sizeof(case1)/sizeof(case1[0]), sizeof(case1[0])/sizeof(case1[0][0]), case1);
    walk(sizeof(case2)/sizeof(case2[0]), sizeof(case2[0])/sizeof(case2[0][0]), case2);
    walk(sizeof(case3)/sizeof(case3[0]), sizeof(case3[0])/sizeof(case3[0][0]), case3);
    walk(sizeof(case4)/sizeof(case4[0]), sizeof(case4[0])/sizeof(case4[0][0]), case4);
    walk(sizeof(case5)/sizeof(case5[0]), sizeof(case5[0])/sizeof(case5[0][0]), case5);
    walk(sizeof(case6)/sizeof(case6[0]), sizeof(case6[0])/sizeof(case6[0][0]), case6);
    walk(sizeof(case7)/sizeof(case7[0]), sizeof(case7[0])/sizeof(case7[0][0]), case7);
    
    return 0;
}
