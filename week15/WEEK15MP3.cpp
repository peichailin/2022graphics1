#include "CMP3_MCI.h"
#include <stdio.h>
CMP3_MCI mp3;
int main()
{
    mp3.Load("0707.mp3");
    mp3.Play();
    printf("��J�Ʀr�{���N�|�d��");
    int N;
    scanf("%d",&N);
}
