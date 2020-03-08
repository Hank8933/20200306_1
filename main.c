#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void playerA ()
{
    int i,j,k,m,n;
    char colors [3125][6], avail [6] = {'R', 'G', 'B', 'Y' , 'O'};
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            for (k = 0; k < 5; k++)
                for (m = 0; m < 5; m++)
                    for (n = 0; n < 5; n++)
                    {
                        colors [i*5+j*5+k*5+m*5+n][0] = avail [i];
                        colors [i*5+j*5+k*5+m*5+n][1] = avail [j];
                        colors [i*5+j*5+k*5+m*5+n][2] = avail [k];
                        colors [i*5+j*5+k*5+m*5+n][3] = avail [m];
                        colors [i*5+j*5+k*5+m*5+n][4] = avail [n];
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
    char avail[6] = {'R', 'G', 'B', 'Y' , 'O'};
    char temparray[6];

    for (i=0;i<5;i++)
    {
        colors [i] = avail[rand()%5];
    }

    printf("%s\n",colors);

    printf("請輸入由 [R] [G] [B] [Y] [O] 所組成的5個字(可重複) eg: [RGBBB]\n");
    for (;;)
    {
        b=0;
        w=0;
        n++;
        printf("\n第 %d 輪: ",n);
        scanf("%s",guess);
        //printf("%s\n",guess);
        for (i=0;i<5;i++)
        {
            if (colors[i]==guess[i])
                b++;
            for (j=0;j<5;j++)
            {
                if (colors[i]==guess[j])
                {
                    w++;
                    guess[j]='X';
                    break;
                }
            }
        }
        w-=b;
        printf("Black pins: %d ,White pins: %d\n",b,w);
        if (b==5)
        {
            printf("\n遊戲結束!，你總共用了 %d 輪猜出。",n);
            break;
        }
    }



}

int main()
{
    char player;

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

    return 0;
}
