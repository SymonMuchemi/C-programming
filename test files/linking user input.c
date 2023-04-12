#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    int age;
    struct person *nextPerson;
};

struct person *newPerson(const int age)
{
    struct person *newPerson = NULL;
    newPerson = malloc(sizeof(struct person));
    if (newPerson != NULL){
    newPerson->age = age;
    newPerson->nextPerson = NULL;
    printf("Person created at %p\n", newPerson);
    }
    else{
        printf("Allocation failure!");
    }
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

void printList(const struct person *list){
    printf("The list:\n");
    const struct person *t;
    t = list;
    if(t == NULL){
        printf("List is EMPTY!");
    }
    else{
        while (t)
        {
            printPerson(t, "t");
            t = t->nextPerson;
        }
        
    }
}
void cleanUp(struct person *list){
    struct person *next;
    while (list)
    {
        next = list->newPerson;
        printf("Cleaning Up!");
        free(list);
        list = next;
    }
    
}

int main(void)
{
    struct person *first = NULL;
    struct person *added = NULL;

    char command[64];
    int age;

    while (1)
    {
        printf("Enter a command or value:");
        fgets(command, 64, stdin);

        if (strcmp("q\n", command) == 0)
        {
            printf("quitting...\n");
        }
        else if (strcmp("print\n",command) == 0)
        {
            printf("quitting...\n");
        }
        else if(sscanf(command, "%d, &age") != 0){
            printf("Adding %d",  &age);

            if (first == NULL)
            {
                first = newPerson(age);
                if(first != NULL){
                    added = first;
                }
            } 
        }
        else{
            added->nextPerson = newPerson(age);
            if (added->nextPerson != NULL){
                added = added->nextPerson;
            }       
        }
    }
    cleanUp(first);
    return (0);
}