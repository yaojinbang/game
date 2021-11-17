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
        printf("�������Ų��׵�����>:");
        scanf("%d%d", &x, &y);
        if(x>=1 && x<=row && y>=1 && y<=col)
        {
            //����Ϸ�
            //����
            if(mine[x][y] == '1')
            {
                printf("���ź����㱻ը����\n");
                break;
            }
            //������ ����x y������Χ�м�����
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
            printf("��������Ƿ�������������\n");
        }
   }
   if(win == row*col-EASY_COUNT)
   {
       printf("��ϲ�����׳ɹ�\n");
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
    //�׵���Ϣ�洢 ���ú��׵���Ϣ 11*11
    char mine[ROWS][COLS] = {0};
    //�Ų��׵���Ϣ 9*9
    char show[ROWS][COLS] = {0};
    //���̳�ʼ��
    InitBoard(mine,ROWS,COLS, '0');
    InitBoard(show,ROWS,COLS, '*');
    //��ӡ����
    //DisplayBoard(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);
    //������
    SetMine(mine, ROW, COL);
    DisplayBoard(mine, ROW, COL);
    //ɨ��
    FindMine(mine, show, ROW, COL);
    DisplayBoard(mine, ROW, COL);

}