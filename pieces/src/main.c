#include "game.h"

int main(int argc, char* argv[])
{
    int input = 0;
    do{
      menu();
      printf("������:> ");
      scanf("%d", &input); 
      switch (input)
      {
        case 1:
                game();
                break;
        case 0:
                printf("��Ϸ����\n");
                break;
        default:
                printf("�����������������\n");
                break;
      }
    }while(input);
    return 0;
}