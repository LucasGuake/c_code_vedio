#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#pragma warning(disable:4996)

// 设置光标位置
static void SetPos(int x, int y)
{
    COORD point = { x, y };
    HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(HOutput, point);
}

// 清屏函数
void ClearScreen()
{
    system("cls");
    SetPos(0, 0);
}

int main()
{
    char vstart = 0;
    char check = 'y';
    printf("请进入全屏获得最佳播放效果[按y继续]\n");
    // 读取单个字符输入
    scanf(" %c", &vstart);
    if (vstart == check)
    {
        FILE* fp;
        char buf[150], add[60], ai[5];
        int i = 1, delay = 33;
        clock_t stime = 0, ftime = 0;

        stime = clock();

        // 循环显示文本文件，直到文件不存在
        while (1)
        {
            // 控制显示速度
            if (i % 30 == 0)
            {
                delay = 43;
            }
            else
            {
                delay = 33;
            }

            // 拼接文件路径
            strcpy(add, "..\\text\\txt (");
            sprintf(ai, "%d", i);
            strcat(add, ai);
            strcat(add, ").txt");

            // 控制显示时间间隔
            ftime = clock();
            if (ftime - stime >= delay)
            {
                fp = fopen(add, "r");

                if (NULL == fp)
                {
                    // 文件不存在时退出循环（停止播放）
                    break;
                }
                else
                {
                    // 清屏后显示新内容
                    ClearScreen();
                    while (fgets(buf, 150, fp))
                    {
                        printf("%s", buf);
                    }
                    fclose(fp);
                    i++;
                    stime = clock();
                }
            }
        }

        // 全部显示完成后清屏
        ClearScreen();
    }
    else
    {
        printf("您的输入错误\n");
        return 0;
    }
    printf("------------------------------------------------------------------\n");
    printf("所有内容已显示完毕\n");

    return 0;
}
