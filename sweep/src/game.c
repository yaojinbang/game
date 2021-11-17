#include "game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    for(int j=0; j<=col; j++)
    {
        printf("%d ",j);
    }
    printf("\n");
    for(int i=1; i<=row; i++)
    {
        printf("%d ",i);
        for(int j=1; j<=col; j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }

}

void SetMine(char board[ROWS][COLS], int row, int col)
{
   
    int count = EASY_COUNT;
    while(count)
    {
        int x = rand()%row+1;
        int y = rand()%col+1;
        if(board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
    

}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
   while(win < row*col-EASY_COUNT)
   {
        printf("请输入排查雷的坐标>:");
        scanf("%d%d", &x, &y);
        if(x>=1 && x<=row && y>=1 && y<=col)
        {
            //坐标合法
            //是雷
            if(mine[x][y] == '1')
            {
                printf("很遗憾，你被炸死了\n");
                break;
            }
            //不是雷 计算x y坐标周围有几个雷
            else
            {
                int count = get_mine_count(mine, x, y);
                show[x][y] = count + '0';
                DisplayBoard(show, row, col);
                win++;
            }

        }
        else
        {
            printf("输入坐标非法，请重新输入\n");
        }
   }
   if(win == row*col-EASY_COUNT)
   {
       printf("恭喜你排雷成功\n");
   }


}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    return mine[x-1][y] + 
    mine[x-1][y-1] +
    mine[x][y-1] +
    mine[x+1][y-1] +
    mine[x+1][y] +
    mine[x+1][y+1]+
    mine[x][y+1]+
    mine[x-1][y+1] - 8*'0'; 
}



void game()
{
    //雷的信息存储 布置好雷的信息 11*11
    char mine[ROWS][COLS] = {0};
    //排查雷的信息 9*9
    char show[ROWS][COLS] = {0};
    //雷盘初始化
    InitBoard(mine,ROWS,COLS, '0');
    InitBoard(show,ROWS,COLS, '*');
    //打印棋盘
    //DisplayBoard(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);
    //布置雷
    SetMine(mine, ROW, COL);
    DisplayBoard(mine, ROW, COL);
    //扫雷
    FindMine(mine, show, ROW, COL);
    DisplayBoard(mine, ROW, COL);

}