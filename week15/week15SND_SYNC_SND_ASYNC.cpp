#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()之前\n");
     PlaySound("07072006.wav",NULL,SND_ASYNC);
     while(1)
     {
          printf("請輸入數字:");
        int N;

        scanf("%d",&N);
        if(N==1) PlaySound("do.wav",NULL,SND_ASYNC);
        if(N==2) PlaySound("re.wav",NULL,SND_ASYNC);
        if(N==3) PlaySound("mi.wav",NULL,SND_ASYNC);
     }
    ///不等待,互動性較佳,比較快執行到下一行

}
