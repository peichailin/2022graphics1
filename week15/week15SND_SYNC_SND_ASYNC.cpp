#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()���e\n");
     PlaySound("07072006.wav",NULL,SND_ASYNC);
     while(1)
     {
          printf("�п�J�Ʀr:");
        int N;

        scanf("%d",&N);
        if(N==1) PlaySound("do.wav",NULL,SND_ASYNC);
        if(N==2) PlaySound("re.wav",NULL,SND_ASYNC);
        if(N==3) PlaySound("mi.wav",NULL,SND_ASYNC);
     }
    ///������,���ʩʸ���,����ְ����U�@��

}
