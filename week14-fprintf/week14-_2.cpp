

#include <stdio.h>
int main()
{

    FILE*fout=fopen("flie.txt","w+");
    fprintf(fout,"3.1415926\n");
    fclose(fout);

    float angle=0;
    FILE*fin=fopen("flie.txt","r");
    fscanf(fin,"%f",&angle);
    printf("Ū�쪺����:%f",angle);
    fclose(fin);

}
