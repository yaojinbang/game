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
     printf("�����:>\n");
     while(1)
     {
        printf("������Ҫ�µ�����:>");
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
                printf("�����걻ռ��\n");
            }

        }
        else
        {
            printf("����Ƿ�,����������\n");
        }

     }

 }

 void ComputerMove(char board[ROW][COL],int row,int col)
 {
     srand((unsigned int)time(NULL));
     int x = 0;
     int y = 0;
     printf("������:>\n");
     while(1)
     {
         x = rand()%ROW;
         y = rand()%COL;
        //  printf("����Ҫ�ߵ�������:>%d %d\n", x, y);
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

//�жϳ����ֿ��� 1.���ʤ�� '*' 2.����ʤ�� '#' 3.ƽ�� 'Q' 4.������Ϸ 'C'
char IsWin(char board[ROW][COL], int row, int col)
{
    //������
    for(int i=0; i<row; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }
    //������
    for(int j=0; j<col; j++)
    {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
        {
            return board[0][j];
        }
    }
    //�����Խ���
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
    //�������߳���������Ϣ
    char board[ROW][COL] = {0};
    //��ʼ��������Ϣ
    InitBoard(board,ROW,COL);
    //��ӡ����
    DisplayBoard(board,ROW,COL);
    //����
    while(1)
    {
        //�������
        PlayrMove(board,ROW,COL);
        //��ӡ����
        DisplayBoard(board,ROW,COL);
        //�ж��Ƿ�ʤ��
        ret = IsWin(board,ROW,COL);
        if(ret != 'C')//˵���Ѿ��ó����
        {
            break;
        }
        //��������
        ComputerMove(board,ROW,COL);
        //��ӡ����
        DisplayBoard(board,ROW,COL);
        //�ж��Ƿ�ʤ��
        ret = IsWin(board,ROW,COL);
        if(ret != 'C')//˵���Ѿ��ó����
        {
            break;
        }
        
    }
    if(ret == '*')
    {
        printf("��ϲ��һ��ʤ��!!!\n");
    }
    else if(ret == '#')
    {
        printf("��ϲ���Ի��ʤ��!!!\n");
    }
    else if(ret == 'Q')
    {
        printf("���ƽ��\n");
    }
}