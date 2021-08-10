#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int T, i, j, temp;
    int n[100];
    int prevCntZero, CntZero;
    int prevCntOne, CntOne;

    scanf("%d", &T);
    for(i = 0; i < T; i++)
    {
        scanf("%d", &n[i]);
    }

    for(i = 0; i < T; i++)
    {
        if(n[i] == 0)
        {
            CntZero = 1;
            CntOne = 0;
        }
        else if(n[i] == 1)
        {
            CntZero = 0;
            CntOne = 1;
        }
        else
        {
            prevCntZero = 0;
            CntZero     = 1;

            prevCntOne  = 1;
            CntOne      = 1;
            for(j = 2; j < n[i]; j++)
            {
                temp        =  CntZero;
                CntZero     += prevCntZero;
                prevCntZero = temp;

                temp        = CntOne;
                CntOne      += prevCntOne;
                prevCntOne  = temp;
            }
        }

        printf("%d %d\n", CntZero, CntOne);
    }

    return 0;
}
