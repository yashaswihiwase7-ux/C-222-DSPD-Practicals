#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    char ch;

    fp1 = fopen("file1.txt","r");
    fp2 = fopen("file2.txt","w");

    if(fp1 == NULL || fp2 == NULL)
    {
        printf("File not opened correctly\n");
        return 1;
    }
    else
    {
        while((ch = fgetc(fp1)) != EOF)
        {
            fputc(ch, fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);
    printf("File copied successfully!\n");
    return 0;
}