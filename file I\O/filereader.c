#include <stdio.h>

int main(){

    FILE *fileptr; // declaring the file pointer variable
    
    char contentsOfFile[100];

    fileptr = fopen("file101.txt", "r"); // reading the file to open it
    printf("%s", fgets(contentsOfFile, 50, fileptr));

    fclose(fileptr);

}