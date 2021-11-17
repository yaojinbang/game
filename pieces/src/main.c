#include "game.h"

int main(int argc, char* argv[])
{
    int input = 0;
    do{
      menu();
      printf("请输入:> ");
      scanf("%d", &input); 
      switch (input)
      {
        case 1:
                game();
                break;
        case 0:
                printf("游戏结束\n");
                break;
        default:
                printf("输入错误，请重新输入\n");
                break;
      }
    }while(input);
    return 0;
}