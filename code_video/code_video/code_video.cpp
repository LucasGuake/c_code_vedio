#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#pragma warning(disable:4996)

// ���ù��λ��
static void SetPos(int x, int y)
{
    COORD point = { x, y };
    HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(HOutput, point);
}

// ��������
void ClearScreen()
{
    system("cls");
    SetPos(0, 0);
}

int main()
{
    char vstart = 0;
    char check = 'y';
    printf("�����ȫ�������Ѳ���Ч��[��y����]\n");
    // ��ȡ�����ַ�����
    scanf(" %c", &vstart);
    if (vstart == check)
    {
        FILE* fp;
        char buf[150], add[60], ai[5];
        int i = 1, delay = 33;
        clock_t stime = 0, ftime = 0;

        stime = clock();

        // ѭ����ʾ�ı��ļ���ֱ���ļ�������
        while (1)
        {
            // ������ʾ�ٶ�
            if (i % 30 == 0)
            {
                delay = 43;
            }
            else
            {
                delay = 33;
            }

            // ƴ���ļ�·��
            strcpy(add, "..\\text\\txt (");
            sprintf(ai, "%d", i);
            strcat(add, ai);
            strcat(add, ").txt");

            // ������ʾʱ����
            ftime = clock();
            if (ftime - stime >= delay)
            {
                fp = fopen(add, "r");

                if (NULL == fp)
                {
                    // �ļ�������ʱ�˳�ѭ����ֹͣ���ţ�
                    break;
                }
                else
                {
                    // ��������ʾ������
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

        // ȫ����ʾ��ɺ�����
        ClearScreen();
    }
    else
    {
        printf("�����������\n");
        return 0;
    }
    printf("------------------------------------------------------------------\n");
    printf("������������ʾ���\n");

    return 0;
}
