#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int black (char *array,char *array2)  //找黑標
{
    int i;
    int b=0;
    for (i=0; i<5; i++)
    {
        if (array[i]==array2[i])
            b++;
    }
    return b;
}

int white (char *array,char *array2)  //找白標
{
    int i,j;
    int w=0;
    for (i=0; i<5; i++) //找白標
    {
        for (j=0; j<5; j++)
        {
            if (array[j]==array2[i])
            {
                w++;
                array[j]='X';
                break;
            }
        }
    }
    return w;
}

void playerA ()
{
    srand(time(NULL));
    int i,j,k,m,n,p=0,q=3125;
    char guess[6];
    int b,w,b1,w1;
    char temparray[6];
    char colors [3125][6], avail [6] = {'R', 'G', 'B', 'Y', 'O'};

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            for (k = 0; k < 5; k++)
                for (m = 0; m < 5; m++)
                    for (n = 0; n < 5; n++)
                    {
                        colors[p][5] = '\0';
                        colors[p][0] = avail[i];
                        colors[p][1] = avail[j];
                        colors[p][2] = avail[k];
                        colors[p][3] = avail[m];
                        colors[p++][4] = avail[n];
                    }

    printf("請想好由 [R] [G] [B] [Y] [O] 所組成的5個字(可重複) eg: [RGBBB]，五秒後開始遊戲\n");
    Sleep(5000);

    n=0;  //輪數
    m=3125;  //所有可能
    for (;;)
    {
        b=0;
        w=0;
        n++;

        if (m==0)
        {
            printf("\n無解!\n");
            return ;
        }
        else
        {
            j=rand()%m;
            //printf("%d %d \n",j,m);
            for (i=0; i<6; i++)
            {
                guess[i] = colors[j][i];
            }
        }

        printf("\n第 %d 輪: ",n);

        printf("%s 請輸入 [Black pins] and [White pins] 數量: ",guess);
        scanf("%d %d",&b,&w);
        if (b==5)
        {
            printf("\n遊戲結束!，電腦總共用了 %d 輪猜出。\n\n",n);
            break;
        }

        m=0;  //可能答案數量

        for (i=0; i<q; i++)
        {
            for (j=0; j<5; j++)
            {
                temparray[j]=colors[i][j];
            }
            temparray[5] = '\0';

            b1=black(temparray,guess);  //找黑標
            w1=white(temparray,guess);  //找白標
            w1-=b1;
            //printf("%s %d %d ",colors[i],b1,w1);  //所有陣列
            if (b==b1&&w==w1)
            {
                //printf("[%s] %d %d ",colors[i],b,w);  //所有符合
                for (p=0; p<6; p++)
                {
                    colors[m][p]=colors[i][p];
                }
                m++;
            }
        }
        q=m;
        //printf("m=%d\n",m);  //符合數
    }
}

void playerB ()
{
    srand(time(NULL));
    int i,j;
    int n=0;  //輪數
    int b,w;  //Black pins & White pins
    char guess[6];
    char colors[6] = {'\0'};
    char avail[6] = {'R', 'G', 'B', 'Y', 'O'};

    for (i=0; i<5; i++)
    {
        colors[i] = avail[rand()%5];
    }
    //printf("%s\n",colors);  //答案

    printf("請輸入由 [R] [G] [B] [Y] [O] 所組成的5個字(可重複) eg: [RGBBB]\n");
    for (;;)
    {
        n++;
        printf("\n第 %d 輪: ",n);
        scanf("%s",guess);
        b=black(colors,guess);  //找黑標
        w=white(guess,colors);  //找白標
        w-=b;
        printf("Black pins: %d ,White pins: %d\n",b,w);
        if (b==5)
        {
            printf("\n遊戲結束!，你總共用了 %d 輪猜出。\n\n",n);
            break;
        }
    }
}

int main()
{
    char player,replay;
    do
    {
        do
        {
            printf("請輸入 [A] 或 [B] 來選擇當 [玩家A](出題) 或 [玩家B](猜題): ");
            scanf(" %c",&player);
            if(player=='A')
            {
                printf("\n你選擇了 [玩家A]\n\n");
                playerA();
            }
            else if (player=='B')
            {
                printf("\n你選擇了 [玩家B]\n\n");
                playerB();
            }
            else
                printf("\n無效的選擇!請重新輸入!\n\n");
        }
        while (!((player == 'A') || (player == 'B')));
        printf("輸入[y]再玩一次，其他離開遊戲: ");
        scanf(" %c",&replay);
        printf("\n");
    }
    while (((replay == 'Y') || (replay == 'y')));
    system("pause");
    return 0;
}
