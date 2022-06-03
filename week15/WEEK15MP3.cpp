#include "CMP3_MCI.h"
#include <stdio.h>
CMP3_MCI mp3;
int main()
{
    mp3.Load("0707.mp3");
    mp3.Play();
    printf("輸入數字程式就會卡住");
    int N;
    scanf("%d",&N);
}
