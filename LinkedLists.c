#include <stdio.h>
#include <stdlib.h>

struct person
{
    int age;
};


struct person *newPerson(const int age){
    struct person *newPerson = NULL;
    newPerson = malloc(sizeof(struct person));
    newPerson->age = age;

    printf("Person created at %p\n", newPerson);
    return newPerson;
}
void printPerson(const struct person *person, const char *comment){
    if (person == NULL)
        printf("%s is NULL\n", comment);

    else {
        printf("%s: Age: %d address: %p", comment, person->age, person);
    }
}

int main(void){
    struct person *first = NULL;
    struct person *second = NULL;

    first = newPerson(20);
    second = newPerson(30);

    printPerson(first, "First Person");
    printPerson(second, "Second Person");

    free(first);
    free(second);

    first = NULL;
    second = NULL; 
}