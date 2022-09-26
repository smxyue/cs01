// cs01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

char M[] = "65635365625235325265635365615135315125235325215135315165635365625235325265635365605035305025235325205035305015135315125235325215135315105035305025235325205035305065635356252353252656353656151353151252353252151353151656353656252353252656353454";
char G[] = "254355153256235251056355461151336154151034156110550150052030256256132252350325112052333054055231255051336154150665264150266506012264453605631520256431054354632404350334153250253251352352045150130156213436252353223135051260513356201524514343432";
char B[] = "22222222213333333331";
char matrix[10][10];
int currentRow = 0;
int currentCol = 0;
int score = 0;
void initMatrix()
{
    srand(int(time(0)));
    for (int i = 0;i < 10;i++)
    {
        for (int j = 0;j < 10;j++)
        {
            int val = rand();
            if (val % 2 == 0)
            {
                matrix[i][j] = 1;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }
}
void printMatrix()
{
    printf("\n\r Matrix table \n\r");
    for (int i = 0;i < 10;i++)
    {
        for (int j = 0;j < 10;j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n\r");
    }
}
int randMove()
{
    int step = rand() % 6;
    while (step == 0 && currentRow == 0)
    {
        step = rand() % 6;
    }
    while (step == 1 && currentRow == 9)
    {
        step = rand() % 6;
    }
    while (step == 2 && currentCol == 9)
    {
        step = rand() % 6;
    }
    while (step == 3 && currentRow == 0)
    {
        step = rand() % 6;
    }
    return step;
}
void move(int dir)
{
    //0=向北移动，1=向南移动，2=向东移动，3=向西移动，4=不动，5=捡拾罐子，6=随机移动;
    if (dir > 6 || dir < 0)
        return;
    if (dir == 6)
        dir = randMove();
    switch (dir)
    {
    case 0:
        currentRow--;
        break;
    case 1:
        currentRow++;
        break;
    case 2:
        currentCol++;
        break;
    case 3:
        currentCol--;
        break;
    case 4:
        break;
    case 5:
        if (matrix[currentRow][currentCol] == 1)
            score += 10;
        break;
    }
    if (currentRow < 0)
        currentRow = 0;
    if (currentRow > 9)
        currentRow = 9;
    if (currentCol < 0)
        currentCol = 0;
    if (currentCol > 9)
        currentCol = 9;
}

void testM()
{
    currentCol = 0;
    currentRow = 0;
    score = 0;
    for (int i = 0;i < 243;i++)
    {
        int s = M[i] - '0';
        move(s);
    }
    printf("\n\rM mehtod score:%d", score);
}
void testG()
{
    currentCol = 0;
    currentRow = 0;
    score = 0;
    for (int i = 0;i < 243;i++)
    {
        int s = G[i] - '0';
        move(s);
    }
    printf("\n\rG mehtod score:%d", score);
}
void testB()
{
    currentCol = 0;
    currentRow = 0;
    score = 0;
    for (int t = 0;t < 5;t++)
    {
        for (int i = 0;i < 21;i++)
        {
            move(5);
            int val = B[i] - '0';
            move(val);
        }
    }
}
int main()
{
    std::cout << "Hello World!\n";
    int totalM = 0;
    int totalG = 0;
    int totalB = 0;
    for (int k = 0;k < 100000;k++)
    {
        initMatrix();
        testM();
        totalM += score;
        testG();
        totalG += score;
        testB();
        totalB += score;
    }
    printf("\n\rM:%d    G:%d    B:%d", totalM / 100000, totalG / 100000,totalB/100000);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
