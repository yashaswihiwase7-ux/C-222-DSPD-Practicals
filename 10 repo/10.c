#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    char ch;
    fp1 = fopen("inputfile.txt","r");
    fp2 = fopen("outputfile.txt","w");

    if(fp1 == NULL )
    printf("File not opened correctly\n");
       
     if(fp2 == NULL)
    {
        printf("File not opened correctly\n");
 
    }
    else
    {
        while((ch = fgetc(fp1)) != EOF)
        {
            fputc(ch, fp2);
             printf("File copied successfully!\n");
        }
    }

    fclose(fp1);
    fclose(fp2);
     printf("File copied successfully!\n");
   return 0;
}