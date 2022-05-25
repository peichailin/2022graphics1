
#include <stdio.h>
int main()
{

    FILE*fout=fopen("flie.txt","w+");
    printf("Hello World!\n");
    fprintf(fout,"Hello World!\n");
    fclose(fout);
}
