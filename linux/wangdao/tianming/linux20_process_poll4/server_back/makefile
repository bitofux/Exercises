# 获取当前目录下的所有.c文件
SRCS := $(wildcard *.c)

# 将获取到的.c文件转换为.o文件
OBJS := $(patsubst %.c,%.o,$(SRCS))

main:$(OBJS)
	gcc $^ -o $@ -pthread

%.o:%.c
	gcc -c $^ -o $@ -g

clean:
	$(RM) $(OBJS) main

rebuild: clean main
