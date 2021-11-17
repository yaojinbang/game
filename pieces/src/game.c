#include "game.h"

void menu()
{
    printf("********************************************\n");
    printf("*******1.begin**********0.exit**************\n");
    printf("********************************************\n");
}


void InitBoard(char board[ROW][COL], int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            board[i][j] = ' ';
        }
    }

}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf(" %c ",board[i][j]);
            if(j < col-1)
            {
                printf("|");
            }
        }
        printf("\n");
        if(i < row-1)
        {
            for(int j=0; j<col; j++)
            {
                printf("---");
                if(j < col-1)
                {
                    printf("|");
                }
            }
            printf("\n");
        }
       
        
    }
}

 void PlayrMove(char board[ROW][COL],int row,int col)
 {
     int x =0,y = 0;
     printf("玩家走:>\n");
     while(1)
     {
        printf("请输入要下的坐标:>");
        scanf("%d%d", &x, &y);
        if(x>=1 && x<=row && y>=1 && y<=col)
        {
            if(board[x-1][y-1] == ' ')
            {
                board[x-1][y-1] = '*';
                break;
            }
            else
            {
                printf("该坐标被占用\n");
            }

        }
        else
        {
            printf("坐标非法,请重新输入\n");
        }

     }

 }

 void ComputerMove(char board[ROW][COL],int row,int col)
 {
     srand((unsigned int)time(NULL));
     int x = 0;
     int y = 0;
     printf("电脑走:>\n");
     while(1)
     {
         x = rand()%ROW;
         y = rand()%COL;
        //  printf("电脑要走的坐标是:>%d %d\n", x, y);
        if(board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
         
     }
 }
int IsFull(char board[ROW][COL],int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;

}

//判断出四种可能 1.玩家胜利 '*' 2.电脑胜利 '#' 3.平局 'Q' 4.继续游戏 'C'
char IsWin(char board[ROW][COL], int row, int col)
{
    //横三行
    for(int i=0; i<row; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }
    //竖三列
    for(int j=0; j<col; j++)
    {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
        {
            return board[0][j];
        }
    }
    //两个对角线
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return board[0][0];
    }
    else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return board[0][2];
    }
    if(IsFull(board, ROW, COL) == 1)
    {
        return 'Q';
    }
    return 'C';

}

void game()
{
    char ret = 0;
    //数组存放走出的棋盘信息
    char board[ROW][COL] = {0};
    //初始化棋盘信息
    InitBoard(board,ROW,COL);
    //打印棋盘
    DisplayBoard(board,ROW,COL);
    //下棋
    while(1)
    {
        //玩家下棋
        PlayrMove(board,ROW,COL);
        //打印棋盘
        DisplayBoard(board,ROW,COL);
        //判断是否胜利
        ret = IsWin(board,ROW,COL);
        if(ret != 'C')//说明已经得出结果
        {
            break;
        }
        //电脑下棋
        ComputerMove(board,ROW,COL);
        //打印棋盘
        DisplayBoard(board,ROW,COL);
        //判断是否胜利
        ret = IsWin(board,ROW,COL);
        if(ret != 'C')//说明已经得出结果
        {
            break;
        }
        
    }
    if(ret == '*')
    {
        printf("恭喜玩家获得胜利!!!\n");
    }
    else if(ret == '#')
    {
        printf("恭喜电脑获得胜利!!!\n");
    }
    else if(ret == 'Q')
    {
        printf("打成平局\n");
    }
}