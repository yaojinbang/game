#include "game.h"

void menu()
{
    printf("**********************************\n");
    printf("********     1.play     **********\n");
    printf("********     0.exit     **********\n");
    printf("**********************************\n");

}

void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("������:>");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                    printf("��ʼ��Ϸ\n");
                    game();
                    break;
            case 0:
                    printf("�˳���Ϸ\n");
                    break;
            default:
                    printf("��Ϸ����\n");
                    break;
        }
    } while (input);
    
}


int main(int argc,char* argv[])
{
    test();
    return 0;
}