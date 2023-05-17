#include <stdio.h>

int main()
{
    char ch;
    FILE *fp;
    fp = fopen("EOF_example.txt", "w");
    printf("Enter text then press ctrl+z:\n");

    while ((ch = getchar()) != EOF)
    {
        //putc(ch, fp);
        fprintf(fp, "%c" ,putchar(ch));
    }
    fclose(fp);

    fp = fopen("EOF_example.txt", "r");
    printf("File contains the following text:");

    while ((ch = getc(fp)) != EOF){
        putchar(ch);
    }

    fclose(fp);

    return (0);
}