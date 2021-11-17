SRC = $(wildcard ./src/*.c)#获取当前路径下的所有文件
OBJ = $(patsubst %.c,%.o,$(SRC))#将SRC列表的.c文件替换成.o文件
INC_PATH = ./inc #连接头文件
BIL_PATH = ./lib #连接库文件
image = bin/main
ifdef TOOLCHAIN    #判断TOOLCHAIN是否有定义
	CC = $(TOOLCHAIN)
else 
	CC = gcc
endif

$(image):$(OBJ)
	$(CC) $^ -o $@
$(OBJ):%.o:%.c
	$(CC) $^ -o $@ -c -I $(INC_PATH) -L $(BIL_PATH)

clean:
	$(RM) $(OBJ) $(image)

.PHONY:clean
