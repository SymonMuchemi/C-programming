#include <stdio.h>

int main(){
    FILE *fileptr; // declaring a file pointer variable

    fileptr = fopen("file101.txt", "w"); // opening the file

    // processing the file
    fprintf(fileptr, "%s", "This file was created using the file101.c program\nI feel amazing :)");

    fclose(fileptr); //closing the file

    return (0);
}