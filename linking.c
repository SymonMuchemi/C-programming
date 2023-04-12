#include <stdio.h>
#include <stdlib.h>

struct person
{
    int age;
    struct person *nextPerson;
};

struct person *newPerson(const int age)
{
    struct person *newPerson = NULL;
    newPerson = malloc(sizeof(struct person));
    newPerson->age = age;
    newPerson->nextPerson = NULL;
    printf("Person created at %p\n", newPerson);
    return newPerson;
}
void printPerson(const struct person *person, const char *comment)
{
    if (person == NULL)
        printf("%s is NULL\n", comment);

    else
    {
        printf("%s: \nAge: %d \naddress: %p \nnext: %p\n\n", comment, person->age, person, person->nextPerson);
    }
}

int main(void)
{
    struct person *first = NULL;
    struct person *second = NULL;

    first = newPerson(20);
    second = newPerson(30);

    first->nextPerson = second;

    printPerson(first, "First Person");
    printPerson(second, "Second Person");

    free(first);
    free(second);

    first = NULL;
    second = NULL;
}