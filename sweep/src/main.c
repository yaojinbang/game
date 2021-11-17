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
        printf("请输入:>");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                    printf("开始游戏\n");
                    game();
                    break;
            case 0:
                    printf("退出游戏\n");
                    break;
            default:
                    printf("游戏结束\n");
                    break;
        }
    } while (input);
    
}


int main(int argc,char* argv[])
{
    test();
    return 0;
}