#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x1;
    int y1;
    int r1;
    int x2;
    int y2;
    int r2;
} Circle_t;

int main(int argc, char* argv[])
{
    int NumOfTestCase;
    Circle_t* pCircle;
    int* pResult;
    int i;
    double distance;
    int abs_sum_r, abs_sub_r;

    (void)argc;
    (void)argv;

    scanf("%d", &NumOfTestCase);

    pCircle = (Circle_t*)malloc(sizeof(Circle_t) * NumOfTestCase);
    pResult = (int*)malloc(sizeof(int) * NumOfTestCase);

    for(i = 0; i < NumOfTestCase; i++)
    {
        scanf(  "%d %d %d %d %d %d", 
                &pCircle[i].x1, &pCircle[i].y1, &pCircle[i].r1, 
                &pCircle[i].x2, &pCircle[i].y2, &pCircle[i].r2);
    }

    for(i = 0; i < NumOfTestCase; i++)
    {
        /*  ########################################
            1. 교점: 2개
                    r1 + r2 > d
            2. 교점: 1개  
                - 내접: 
                    [ r1 + r2 > d ] & [ |r1 - r2| == d ]
                - 외접:
                    r1 + r2 == d
            3. 교점: 0개
                - 멀리 떨어짐
                    r1 + r2 < d
                - 한원 다른원을 포함
                    [ r1 + r2 > d ] & [ |r1 - r2| > d ]
            4. 교점: 무수히 많음
                    [ d == 0 ] & [ r1 == r2 ]
            ########################################
        */
        distance = sqrt(
            pow(pCircle[i].x2 - pCircle[i].x1, 2) + 
            pow(pCircle[i].y2 - pCircle[i].y1, 2));
        abs_sum_r = abs(pCircle[i].r1 + pCircle[i].r2);
        abs_sub_r = abs(pCircle[i].r1 - pCircle[i].r2);
        
        if((pCircle[i].r1 == pCircle[i].r2) && (distance == 0))
        {
            pResult[i] = -1;
        }
        else if((abs_sum_r == distance) || (abs_sub_r == distance))
        {
            pResult[i] = 1;
        }
        else if((abs_sub_r < distance) && (distance < abs_sum_r))
        {
            pResult[i] = 2;
        }
        else
        {
            pResult[i] = 0;
        }

        printf("%d\n", pResult[i]);
    }

    free(pCircle);
    free(pResult);

    pCircle = NULL;
    pResult = NULL;

    return 0;
}
